// ArraAlgs2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// How do you find the duplicate number on a given  integer array? (solution)
// solution referenced in https://hackernoon.com/50-data-structure-and-algorithms-interview-questions-for-programmers-b4b1ac61f5b0
//gives answer on a sorted array, so I'll program solution for a sorted array,
// How do you find the largestand smallest number in an unsorted integer array ? (solution)
// How do you find duplicate numbers in an array if it contains multiple duplicates? (solution)
// no stl but cumbersome plus array gets modified - findMultipleDuplicates() or same as for str in 

#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <iterator>

using namespace std;

int removeDupsFromSortedArray(int arr[], int size) {
    int nodup_idx = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != arr[nodup_idx]) {
            arr[++nodup_idx] = arr[i];
        }
    }
    int new_size = nodup_idx + 1;
    return new_size;
}

pair<int, int> smallestLargestInArray(int arr[], int size) {
    int mymin = INT_MAX, mymax = INT_MIN;
    //std::cout << "min " << mymin << " max " << mymax << endl;
    int i = 0;
    for (; i < size; ++i) {
        if (arr[i] > mymax) {
            mymax = arr[i];
        }
        if (arr[i] < mymin) {
            mymin = arr[i];
        }
        //std::cout << "i= " << i << " min " << mymin << " max " << mymax << endl;
    }
    //std::cout << "min " << mymin << " max " << mymax << endl;
    return make_pair(mymin, mymax);
}

void findMultipleDuplicates() {
    int numRay[] = { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
    int arr_size = sizeof(numRay) / sizeof(numRay[0]);
    cout << "looking for duplicates in array:" << endl;
    for (auto j : numRay) {
        cout << j << " ";
    }
    for (int i = 0; i < arr_size; i++)
    {
        cout << "\nOn step #" << i << " idx is " << numRay[i] % arr_size << endl;
        numRay[numRay[i] % arr_size] = numRay[numRay[i] % arr_size] + arr_size;
        cout << "array is now: ";
        for (auto j : numRay) {
            cout << j << " ";
        }

    }

    cout << "\nThe repeating elements are : " << endl;
    for (int i = 0; i < arr_size; i++)
    {
        if (numRay[i] >= arr_size * 2)
        {
            cout << i << " " << endl;
        }
    }
}

unordered_set<int> findDupsUsingSTL(int arr[], int size) {
    //given that array may only contain numbers from 0 to MaxNum
    //we'll use unordered set to keep numbers as keys
    unordered_set<int> myNums;
    unordered_set<int> myDups;
    for (int i = 0; i < size; ++i) {
        if (myNums.find(arr[i]) == myNums.end()) {
            myNums.insert(arr[i]);
        }
        else {
            myDups.insert(arr[i]);
        }
    }
    return myDups;
}

int main()
{
    std::cout << "Hello World!\n";
    int ai[] = { 1,1,2,3,4,4,5,5,5,6,7,7,7,8,8,9,10 };
    int ai_size = sizeof(ai) / sizeof(ai[0]);
    cout << "size of ai is " << ai_size << endl;

    int new_size = removeDupsFromSortedArray(ai, ai_size);
    for (int i = 0; i < new_size; ++i) {
        cout << ai[i] << " ";
    }
    cout << endl;
    //for (auto i : ai) { //this one gives a glitch, starting from 2: 2 3 4 5 6 7 8 9 10 7 8 8 8 9 9 10 7  and ai min = 1 and
    for(int i = 0; i < ai_size; ++i) { // out: 1 2 3 4 5 6 7 8 9 10 7 7 7 8 8 9 10  and ai min = 1 and max = 10
        cout << ai[i] << " ";
    }
    auto res = smallestLargestInArray(ai, ai_size);
    cout << " and ai min = " << res.first << " and max = " << res.second << endl;
    findMultipleDuplicates();
    cout << "Lets find all dups in current ai:" << endl;
    unordered_set<int>resdups = findDupsUsingSTL(ai, ai_size);
    copy(resdups.begin(), resdups.end(), std::ostream_iterator<int>(cout, " "));
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
