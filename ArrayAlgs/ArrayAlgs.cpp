// ArrayAlgs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// questions about an array in any coding interview, e.g. reversing an array, sorting the array, 
// or searching elements on the array.
//1. find 1 missing number using expSum = N*(N+1)/2
//2. find any number of missing numbers using bitset
//3. write a program to find all pairs of integers in array whose sum is equal to a given number
// using unordered_set which has O(1) for both search and add so effective solution and provides O(n) all together

#include <iostream>
#include <bitset>
#include <unordered_set>

using namespace std;

void reverseArray(int arr[], int size) {
    int i = 0, j = size-1, temp;
    while (i < j) {
        temp = arr[i];
        arr[i++] = arr[j];
        arr[j--] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int find1missingNumber(int arr[], int size) {
    //expected set of numbers 1-N(incuding) with one missing
    int N = size + 1; //1 more for missing number
    int expSum = N * (N + 1) / 2;
    int actSum = 0;
    for (int i = 0; i < size; ++i) {
        actSum += arr[i];
    }
    return expSum - actSum;
}

void findNmissingDigits(int arr[], int size) {
    const int max = 10;
    bitset<max> alldigits;
    for (int i = 0; i < size; ++i)
        alldigits.set(arr[i], 1); // setting a bit for found number
    for (int j = 0; j < 10; ++j) {
        if (!alldigits.test(j)) {
            cout << "Digit " << j << " is missing" << endl;
        }
    }
}

void printPairsWithCertainSum(int arr[], const int size, const int sum) {
    unordered_set<int> hashedVals;
    for (int i = 0; i < size; ++i) {
        //target is a needed element to give sum added to value
        int target = sum - arr[i];
        if (hashedVals.find(target) == hashedVals.end()) {
            hashedVals.insert(arr[i]);
        }
        else {
            cout << "Pair (" << arr[i] << "," << target << ") gives sum " << sum << endl;
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
    int myarr[] = { 3,8,2,5,9,1,6,2,7,4 };
    int arr_size = sizeof(myarr) / sizeof(myarr[0]);
    //printArray(myarr, arr_size);
    for (auto i : myarr)
        std::cout << i << " ";
    reverseArray(myarr, arr_size);
    cout << "\nReversed array:" << endl;
    printArray(myarr, arr_size);
    int myarr2[] = { 1,2,3,5,6,7,9 };
    arr_size = sizeof(myarr2) / sizeof(myarr2[0]);
    printArray(myarr2, arr_size);
    cout << "Missing number: " << find1missingNumber(myarr2, arr_size) << endl;
    findNmissingDigits(myarr2, arr_size);
    printPairsWithCertainSum(myarr2, arr_size, 10);
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
