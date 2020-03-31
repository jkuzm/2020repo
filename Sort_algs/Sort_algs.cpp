// Sort_algs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1. Bubble sort - courtesy of https://www.geeksforgeeks.org/bubble-sort/
// 2. quick sort
// 2.1 quick sort iteration using stack
// 3 Insert sort
// 4. Merge sort - good explanation here https://www.youtube.com/watch?v=TzeBrDU-JaY

#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], size_t size) {
    cout << "array is bubble-sorted" << endl;
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int partition(int arr[], int l, int r, int pivot) {
    //cout << "entering with l r pivot" << l << " " << r << pivot << endl;
    while (l <= r) {
        while (arr[l] < pivot) {
            //cout << "l=" << l;
            l++;
        }
        while (arr[r] > pivot) {
            //cout << "r=" << r;
            r--;
        }
        if (l <= r) {
            //cout << "swapping idxes [" << l << "]=" << arr[l]  << " , [" << r << "]=" << arr[r]  << endl;
            swap(&arr[l], &arr[r]);
            l++;
            r--;
        }
    }
    return l;
}

void quicksort_recursion(int arr[], int l, int r) {
    //cout << "entering with l r " << l << " " << r << endl;
    if (l >= r) //base line when recursion ends;
        return;
    int pivot = arr[(r+l)/2];
    int parting_idx = partition(arr, l, r, pivot);
    //cout << "parting_idx" << parting_idx << endl;
    quicksort_recursion(arr, l, parting_idx - 1);
    quicksort_recursion(arr, parting_idx, r);
}

void quicksort_r(int arr[], size_t size) {
    cout << "array is quick-sorted recursively, size " << size << endl;
    quicksort_recursion(arr, 0, size-1);
}

void quicksort_iteration(int arr[], const int left, const int right) {
    int l = left;
    int r = right;
    cout << "array is quick-sorted iteratively, l r = " << l << r << endl;
    //constexpr int stack_size = right - left - 1;
    const int stack_size = 30;
    int stack[stack_size];
    int top = -1;
    //push initial boundaries
    stack[++top] = l;
    stack[++top] = r;
    while (top >= 0) {
        //pop boundaries
        r = stack[top--];
        l = stack[top--];
        //set pivot element
        int pivot = arr[(r + l) / 2];
        int part_idx = partition(arr, l, r, pivot);
        //if there are element(s) on left side of pivot - push its boundaries to stack
        if (part_idx - l > 1) {
            stack[++top] = l;
            stack[++top] = part_idx-1;
        }
        //if there are element(s) on right side of pivot
        if (r - part_idx >= 1) {
            stack[++top] = part_idx - 1;
            stack[++top] = r;
        }
    }
}

void quicksort_i(int arr[], size_t size) {
    quicksort_iteration(arr, 0, size - 1);
}

void insert_sort(int arr[], size_t size) {
    cout << "insert sort" << endl;
     for (int i = 1; i < (int)size; ++i) {
        int j = i; 
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(&arr[j - 1], &arr[j]);
            j--;
        }
    }
}
#define MY_ARR_MAX 20

void merge(int arr[], int l, int m, int r) {
    int i, j, k, nl, nr;
    int larr[MY_ARR_MAX];
    int rarr[MY_ARR_MAX];
    nl = m - l + 1;
    nr = r - m;
    for (i = 0; i < nl; i++)
        larr[i] = arr[l + i];
    for (j = 0; i < nl; j++)
        rarr[j] = arr[m+1+j];
    i = 0; j = 0; k = l;
    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j])
            arr[k++] = larr[i++];
        else
            arr[k++] = rarr[j++];
    }
    while(i < nl) //if leftover here after both not empty
        arr[k++] = larr[i++];
    while(j < nr) //if leftover here after both not empty
        arr[k++] = rarr[j++];
}

void merge_sort(int arr[], int l, int r) {
    int m;
    if (l < r) {
        m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge_sort_recursion(int arr[], size_t size) {
    cout << "Merge sort" << endl;
    merge_sort(arr, 0, size - 1);
}

typedef void (*vfp)(int arr[], size_t size);

void run_sort(vfp func) {
    //lambda to print arrays
    auto print_array = [](auto& arr, size_t len) {for (size_t i = 0; i < len; ++i) { cout << arr[i] << " "; } cout << endl; };
    int ai[]{ 2,5,4,1,7,6,3,8,10,9 };
    size_t ai_size = sizeof(ai) / sizeof(ai[0]);
    print_array(ai, ai_size);
    func(ai, ai_size);
    print_array(ai, ai_size);
}

int main()
{
    std::cout << "Hello World!\n";
    run_sort(bubble_sort);
    run_sort(quicksort_r);
    run_sort(quicksort_i);
    run_sort(insert_sort);
    run_sort(merge_sort_recursion);
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
