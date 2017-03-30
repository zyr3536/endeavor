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
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

//希尔插入排序
template<typename T>
void shellSort(T arr[], int n)
{
    for(int h = n / 2; h > 0; h /= 2)
    {
        for(int i = 1; i < n; ++i)
        {
            int j;
            T tmp = arr[i];
            for(j = i; j >= h && tmp < arr[j - h]; j-= h)
                arr[j] = arr[j - h];
            arr[j] = tmp;
        }
    }
}
// 合并过程
template<typename T>
void merge(T a[],int left, int middle,int right)
{
    int i = left, j = middle + 1;
    if(a[middle] < a[middle + 1])// optimize 2
        return;
    T *aux = new T[right - left + 1];
    for(int i = left, j = 0;i <= right; ++i,++j)
        aux[j] = a[i];
    for(int k = left;k <= right;++k)
    {
        if(i > middle)
            a[k] = aux[j++ - left];
        else if(j > right)
            a[k] = aux[i++ - left];
        else if(aux[j - left] < aux[i - left])
            a[k] = aux[j++ - left];
        else
            a[k] = aux[i++ - left];
    }
    delete aux;
    aux = NULL;
}

//归并排序递归子程序
template<typename T>
void __mergeSort(T a[], int left,int right)
{
    if( left == right)
        return;
    if(right - left < 10)// optimize 1
        insertionSort(a + left,right - left + 1);
    int middle = (left + right) / 2;
    __mergeSort(a, left, middle);
    __mergeSort(a, middle + 1, right);
    merge(a, left, middle, right);
}

//归并排序
template<typename T>
void mergeSort(T a[], int n)
{
    __mergeSort(a, 0, n-1);
}

//归并排序自底向上
template<typename T>
void mergeSortBU(T a[], int n)
{
    for(int size = 1; size <= n; size += size)
    {
        int i;
        for(i = 0;i + 2 * size < n; i += 2 * size)
            merge(a, i, i + size - 1, i + 2 * size - 1);
            if(i + size < n)
                merge(a, i, i + size - 1, n - 1);
    }
}

//Partition过程
template<typename T>
int __partition(T a[],int l,int r)
{
    swap(a[l],a[rand()%(r - l + 1) + l]); //随机选取哨兵
    T v = a[l];
    int j = l;
    for(int i = l + 1;i <= r;++i )
    {
        if(a[i] < v)
        {
            swap(a[++j],a[i]);
        }
    }
    swap(a[l],a[j]);
    return j;
}

//Partition过程(填坑法)
//因为不需要swap，比基本的快排要快
template<typename T>
int __partition_(T a[],int l,int r)
{
    swap(a[l],a[rand()%(r - l + 1) + l]); //随机选取哨兵
    int i = l,j = r;
    T v = a[i];
    while(i < j)
    {
        while(i < j && a[j] > v)
            j--;
        if(i < j)
            a[i++] = a[j];
        while(i < j && a[i] < v)
            i++;
        if(i < j)
            a[j--] = a[i];
    }
    a[i] = v;
    return i;
}

//快速排序递归子程序
template<typename T>
void __quickSort(T a[],int l, int r)
{
    if(l >= r)
        return;
    int p = __partition(a,l,r);
    __quickSort(a,l,p - 1);
    __quickSort(a,p + 1,r);
}


//快速排序
template<typename T>
void quickSort(T a[], int n)
{
    srand(time(NULL));
    __quickSort(a,0, n - 1);
}


int main()
{
    int n = 655360;
    int *arr = SortTestHelper::generateRandomArray(n,0,10);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    int *arr3 = SortTestHelper::copyIntArray(arr,n);
    SortTestHelper::testSort("Shell Sort",shellSort,arr2,n);
    SortTestHelper::testSort("Quick Sort",quickSort,arr,n);
    SortTestHelper::testSort("Merge Sort",mergeSort,arr3,n);
    delete[] arr3;
    delete[] arr2;
    delete[] arr;
    return 0;
}


