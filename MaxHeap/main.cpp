#include "heap.h"
#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;

int main()
{
    MaxHeap<int> maxheap = MaxHeap<int>(100);
    srand(time(NULL));
    for(int i = 0; i < 60; ++i)
        maxheap.insert(rand()%100);
    while(!maxheap.isEmpty())
        cout << maxheap.extractMax()<<" ";
    cout << endl;
    return 0;
}
