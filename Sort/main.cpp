#include "SortTestHelper.h"
#include <iostream>
using namespace std;

//普通选择排序
template<typename T>
void selectionSort(T arr[],int n)
{
    for(int i = 0; i < n; ++i)
    {
        int minIndex = i;
        for(int j = i + 1;j < n; ++j)
            if(arr[j] < arr[minIndex])
            minIndex = j;
        swap(arr[i],arr[minIndex]);
    }
}
//简单插入排序
template<typename T>
void insertionSort(T a[],int n)
{
    for(int i = 1;i < n; ++i)
    {
        T tmp = a[i];
        int j;
        for(j = i; j > 0 && tmp < a[j - 1];j--)//可以提前结束
        {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
}

//希尔排序（插入排序加强版）
template<typename T>
void shellSort(T a[],int n)
{

}
int main()
{
    int n = 10000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n,100);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    SortTestHelper::testSort("Selection Sort",selectionSort,arr,n);
    SortTestHelper::testSort("Insertion Sort",insertionSort,arr2,n);
    //SortTestHelper::PrintArray(arr,n);
    delete[] arr2;
    delete[] arr;
    return 0;
}


