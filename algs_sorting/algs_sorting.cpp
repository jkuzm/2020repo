// algs_sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1. quickSort - using video I most understood although they do java so I do my own code
// https://www.youtube.com/watch?v=SLauY6PpjW4
// for me more intuitive that pivot is chosen in the middle instead of right position
// 2. radix sort. good animation to understand: https://www.youtube.com/watch?v=YXFI4osELGU
// and code is mostly from here: https://www.tutorialspoint.com/cplusplus-program-to-implement-radix-sort

#include <iostream>
#include <algorithm>
#include <list>
#include <cmath> 

using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right, int pivot) {
    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }
        if (left <= right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quicksort(int arr[], int left, int right) {
    if (left >= right) //base line where recursin ends
        return;
    //chosing a pivot value. Ofter in samples its just a value of right, I found more intuitive to use a middle one
    int pivot = arr[(left + right) / 2];
    int index = partition(arr, left, right, pivot);
    quicksort(arr, left, index - 1);
    quicksort(arr, index, right);
}

void radixsort(int arr[], int size) {
    //needed max of array content to know number of digits
    int arr_max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr_max) 
            arr_max = arr[i];
    }
    //find max number of digits 
    int exp = 1;
    int max_order = 0;
    while (arr_max / exp > 0) {
        exp *= 10;
        ++max_order;
    }
    list<int> pocket[10]; //a pocket for each of digits from 0 to 9
    for (int i = 0; i < max_order; ++i) {
        int m = pow(10, i + 1);
        int p = pow(10, i);
        for (int j = 0; j < size; ++j) {
            int temp = arr[j] % m;
            int index = temp / p;
            pocket[index].push_back(arr[j]);
        }
        int count = 0;
        for (int j = 0; j < 10; ++j) {
            //delete from pockets in order back into array
            while (!pocket[j].empty()) {
                arr[count++] = pocket[j].front();
                pocket[j].pop_front();
            }
        }
    }
}
//accessing/printing all data called traversal
void print_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Hello World!\n";
    int myarr[] = { 3,8,2,5,9,1,6,2,7,4 };
    int arr_size = sizeof(myarr) / sizeof(myarr[0]);
    //print_array(myarr, arr_size);
    for (auto i : myarr) {
        cout << i << " ";
    }
    cout << endl;
    quicksort(myarr, 0, arr_size - 1);
    print_array(myarr, arr_size);
    int myarr2[] = { 47,436,12, 890,1020, 89,120 };
    arr_size = sizeof(myarr2) / sizeof(myarr2[0]);
    print_array(myarr2, arr_size);
    radixsort(myarr2, arr_size);
    print_array(myarr2, arr_size);
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
