// Quick Sort with resurssion

#include <bits/stdc++.h>
using namespace std;

int Partition(int a[], int left, int right)
{
    int pivot = a[left];
    while (true)
    {
        while (a[left] < pivot)
            left++;
        while (a[right] > pivot)
            right--;

        if (left < right)
        {
            int temp = a[right];
            a[right] = a[left];
            a[left] = temp;
        }
        else
        {
            return right;
        }
    }
}

void QuickSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = Partition(arr, left, right);
        if (pivot > 1)
            QuickSort(arr, left, pivot - 1);
        if (pivot + 1 < right)
            QuickSort(arr, pivot + 1, right);
    }
}

void QuickSort(int *arr, int len)
{
    QuickSort(arr, 0, len - 1);
}

int main()
{
    int max;
    cout << "\n\nEnter the total number of elements: ";
    cin >> max;
    int *numarray = new int[max];
    cout << "\nEnter the elements: ";
    for (int i = 0; i < max; i++)
    {
        cin >> numarray[i];
    }
    cout << "Before Sorting   : ";
    for (int k = 0; k < max; k++)
        cout << numarray[k] << " ";
    QuickSort(numarray, max);

    cout << "\nThe numbers in ascending orders are given below:\n";
    cout << " \nSorted element: ";
    for (int i = 0; i < max; i++)
    {
        cout << numarray[i];
        cout << "\n";
    }
}
