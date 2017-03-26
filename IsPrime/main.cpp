#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int M;
    cin>>M;
    bool *a = new bool[M];
    memset(a,true,M);
    int r = sqrt(M);
    for(int i = 2;i < r;++i)
    {
        for(int j = i;j < M;j += i)
        {
            a[j + i] = false;
        }
    }
    for(int i = 2;i < M;++i)
    {
        if(a[i] == true)
        {
            cout<<i<<" ";
        }

    }
    delete[] a;
    a = NULL;
    return 0;
}
