# 2020repo
Test1inRepo -
Fraction.cpp simple sample of how to overload
operator

OverloadMembFunc -
operator=(F&& rhs) to move insteadcopy
in main - sample of lambda auto withinEpsilon =

MultiInheritanceTraining -
Point, ColorPointWidePoint and WCPoint - to demonstrate how to do 
virtual classes as parents to resolve diamond problem

STL_elements_learning -
nullptr, decltype
ostream_it for neat inline traverse(print of all vector)
vector into deque
simple lambda for prioritising function (for placement into queue)
^(xor)to find 1 odd number between pairs)
lambda to use first in pair if int for priority in priority_queue
find_if and lambda strlenGT4
findNull
initialize list by array

DataStrAlgorTraining -
find missing element in array of 1-N
swap 2 integers without temp
find middle of list in one iteration ith halfslow it not finished
lambda first >2 number
interview q find dups/duplicate chars in one loop
reverse a str using recursion
check if string is a palindrome using recursion
first non-repeating char in str using 1 traversal

algs_findPermutations_FloydCycleFind -
find and print all permutations of a string using recursive functions
detect a loop in linked nodes using Floyds cycle finding alg

algs_sorting -
quicksort
radix sort, inside - find number of digit in a number

ArrayAlgs -
find 1 missing number
find N missing numbers using bitset
reverse array without using recursion
find all pairs of integers in array whose sum is equal to a given number

ArraAlgs2 -
duplicate number on int array, solution on sorted array
find largest max and least min number in unsorted int aray
find duplicates in array with multiple dulicates
2nd way modifying orig array in one loop
remove duplicates
find dulicates using stl

StringAlgs -
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
