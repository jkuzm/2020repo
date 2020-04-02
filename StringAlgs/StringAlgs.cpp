// StringAlgs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//1. How do you print duplicate characters from a string? (solution)
// - in DataStrAlgorTraining
//2. How do you check if two strings are anagrams of each other ? (solution)
//2.1 simple using stl and assuming there are no repeating chars: using set
//2.2 allows dups, using array of all chars counters
// lambda to fill array, lambda to print array
// send function pointer as argument using typedef
//3. How do you print the first non - repeated character from a string ? (solution)
// - in DataStrAlgorTraining
//4. How can a given string be reversed using recursion ? (solution)
// - in DataStrAlgorTraining
//5. How do you check if a string contains only digits ? (solution)
// curtesy of https://stackoverflow.com/questions/8888748/how-to-check-if-given-c-string-or-char-contains-only-digits
// var1 using method str.find_first_not_of var2 using all_of and isdigit()
//6. How are duplicate characters found in a string ? (solution)
// - in DataStrAlgorTraining
// 7. How do you count a number of vowels and consonants in a given string ? (solution)
// 7.1 vowels and strspn() from http://www.cplusplus.com/forum/beginner/47147/
// nothing not trivial for consonants so lets skip it
// 8. How do you count the occurrence of a given character in a string ? (solution)
// lets use std::count 
// 9. How do you find all permutations of a string ? (solution)
// in algs_findPermutations_FloydCycleFind
// 10. How do you reverse words in a given sentence without using any library method ? (solution)
// 11. How do you check if two strings are a rotation of each other ? (solution)
// using search in a str+str (concatenate to itself and search in a big one 
// 12. How do you check if a given string is a palindrome ? (solution)
//  in DataStrAlgorTraining

#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

inline set<char> strIntoSet(const char s[]) {
    set<char> result;
    for (int i = 0; s[i] != '\0'; ++i) {
        result.insert(s[i]);
    }
    return result;
}

bool ifAnagramWithNoDups(char str1[], char str2[]) {
    set<char> str1_chars = strIntoSet(str1);
    for (int i = 0; str2[i] != '\0'; ++i) {
        if (str1_chars.find(str2[i]) == str1_chars.end())
            return false;
    }
    return true;
}

inline void strIntoAllCharsCountArray(char s[], int all_chars_a_to_z[]) {
    for (int i = 0; s[i] != '\0'; ++i) {
        all_chars_a_to_z[s[i]-'a']++;
    }
}

bool ifAnagramFroma2zdupsallawed(char str1[], char str2[]) {
    //if stl allowed I could do map, but they usually do not alow any stl containers 
    //so lets use simple array
    constexpr size_t chars_size = 'z' - 'a' + 2;
    int chars_of_str1[chars_size], chars_of_str2[chars_size];
    auto fill_array = [](auto& arr, int len, int val) {for (int i = 0; i < len; ++i) arr[i] = val; };
    fill_array(chars_of_str1, chars_size, 0);
    strIntoAllCharsCountArray(str1, chars_of_str1);
    fill_array(chars_of_str2, chars_size, 0);
    strIntoAllCharsCountArray(str2, chars_of_str2);
    for (int i = 0; i < chars_size; ++i) {
        if (chars_of_str1[i] != chars_of_str2[i]) return false;
    }
    return true;
    /* for debug
    auto print_idx_and_val_if_not_zero = [](auto& arr, int len) {
        cout << "lambda on arr size " << len << endl;
        for (int i = 0; i < len; ++i) {
            if (arr[i] > 0) {
                cout << "idx " << i << " val " << arr[i] << endl;
            }
        }
    };
    print_idx_and_val_if_not_zero(chars_of_str1, chars_size);*/
}
typedef bool (*vfc)(char s1[], char s2[]);

inline void reportIfAnagram(char s1[], char s2[], vfc func) {
    cout << "strings \'" << s1 << "\' and \'" << s2 << "\' are";
    //if (!ifAnagramWithNoDups(s1, s2))
    if(!func(s1,s2))
        cout << " not";
    cout << " anagrams" << endl;
}

typedef bool (*vfc1)(string &s);

bool is_digits_var1(string& str) {
    cout << "using method str.find_first_not_of" << endl;

    if (str.find_first_not_of("0123456789") == string::npos)
        return true;
    else
        return false;
}

bool is_digits_var2(string& str) {
    cout << "using method all_of and isdigit" << endl;

    return all_of(str.begin(), str.end(), isdigit);
}


void ifStrContainsOnlyDigits(string str, vfc1 func) {
    cout << "checking string : " << str << endl;
    if(func(str))
        cout << "only digits" << endl;
    else
        cout << "not only digits" << endl;
}


int vowelCount(char str[]) {
    int i = 0, vowels = 0;
    while (str[i] != '\0') {
        if (strspn(&str[i], "aeiou"))
            ++vowels;
        i++;
    }
    return vowels;
}

int occurrencesOfGivenCharInStr(string str, char mych) {
    return std::count(str.begin(), str.end(), mych);
}

void reverseWordsInSentence(char str[]) {
    const int max_words = 10;
    const int max_len_of_word = 20;
    int w_cnt = 0, ch_cnt = 0;
    char words[max_words][max_len_of_word];
    for (int i = 0;  str[i] != '\0' && w_cnt < max_words; ++i) {
        if (!isspace(str[i])) {
            words[w_cnt][ch_cnt++] = str[i];
        }
        else {
            words[w_cnt][ch_cnt] = '\0';
            w_cnt++;
            ch_cnt = 0;
        }
    }
    //closing last word
    words[w_cnt][ch_cnt] = '\0';
    cout << "orig sentence:  " << str << "\nreversed words: ";
    for (int i = w_cnt; i >= 0; --i) {
        cout << words[i] << " ";
    }
    cout << endl;
}

void if_two_strings_are_a_rotation_of_each_other(string str1, string str2) {
    cout << "Strings " << str1 << " and " << str2 << endl;
    if (str1.length() != str1.length()) {
        cout << "not rotation, length is different" << endl;
    }
    string temp = str1 + str1;
    if (temp.find(str2) != string::npos)
        cout << " are a rotation of each other" << endl;
    else
        cout << " are NOT a rotation of each other" << endl;
}

void printReversedStr(char str[], int size) {
    if (size <= 0)
        return;
    printReversedStr(&str[1], size -1);
    cout << str[0];
}

int main()
{
    std::cout << "Hello World!\n";
    char str1[] = "mary";
    char str2[] = "ryma";
    char str3[] = "nyma";
    char str4[] = "creative";
    char str5[] = "reactive";
    char str6[] = "reaactive";
    reportIfAnagram(str1, str2, ifAnagramWithNoDups);
    reportIfAnagram(str2, str3, ifAnagramWithNoDups);
    cout << "check if first func recognizes extra char:" << endl;
    reportIfAnagram(str4, str6, ifAnagramWithNoDups);
    cout << "check if second func recognizes extra char:" << endl;
    reportIfAnagram(str4, str6, ifAnagramFroma2zdupsallawed);
    string onlydigits = "9889652756220";
    string notonlydigits = "9889v6527562b20";
    ifStrContainsOnlyDigits(onlydigits, is_digits_var1);
    ifStrContainsOnlyDigits(notonlydigits, is_digits_var1);
    ifStrContainsOnlyDigits(onlydigits, is_digits_var2);
    ifStrContainsOnlyDigits(notonlydigits, is_digits_var2);
    char word[] = "concatenation";
    cout << "word " << word << " contains " << vowelCount(word) << " vowels" << endl;
    //ifAnagramFroma2zdupsallawed(str4, str2);
    cout << "String " << notonlydigits << " contains char \'a\' " << occurrencesOfGivenCharInStr(notonlydigits, '2') << " times" << endl;
    char nnn[] = "How do you reverse words in a given sentence";
    reverseWordsInSentence(nnn);
    if_two_strings_are_a_rotation_of_each_other("abracad abra", "adabraabrac");
    int str5_size = sizeof(str5) / sizeof(str5[0]);
    cout << "Lets reverse string: " << str5 << " result string is: ";
    printReversedStr(str5, str5_size - 1);
    cout << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
