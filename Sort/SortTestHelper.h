#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H
#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
using namespace std;

namespace SortTestHelper
{
    int* generateRandomArray(int n,int rangeL,int rangeR)
    {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i ++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    template<typename T>
    void PrintArray(T arr[],int n)
    {
        for(int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    template<typename T>
    bool isSort(T arr[], int n)
    {
        for(int i = 0; i < n - 1; ++i)
            if(arr[i] > arr[i + 1])
            return false;
        return true;
    }
    template<typename T>
    T * copyIntArray(T a[],int n)
    {
        T *arr = new int[n];
        copy(a,a + n,arr);
        return arr;
    }

    int *generateNearlyOrderedArray(int n, int swapTimes){
        int *arr = new int[n];
        for(int i = 0 ; i < n ; i ++ )
            arr[i] = i;

        srand(time(NULL));
        for( int i = 0 ; i < swapTimes ; i ++ ){
            int posx = rand()%n;
            int posy = rand()%n;
            swap( arr[posx] , arr[posy] );
        }

        return arr;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[],int), T arr[], int n)
    {
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();
        assert(isSort(arr,n));
        cout <<sortName<<":"<<double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }


}
#endif // SORTTESTHELPER_H
