#include <iostream>
/*
问题描述：把1-9数字放入*，使得 *** + *** = ***成立
解决思路：用DFS
*/
using namespace std;

int a[9];
int book[9];

int ThreeDigitNum(int a,int b,int c)
{
    return a*100 + b * 10 + c;
}
void dfs(int step)
{
    if(step == 9)
    {
        if(ThreeDigitNum(a[0],a[1],a[2]) + ThreeDigitNum(a[3],a[4],a[5]) == ThreeDigitNum(a[6],a[7],a[8]))
        {
           for(int i = 0;i < 9;++i)
            {
                cout<<a[i];
                if(i == 2)
                    cout<<"+";
                if(i == 5)
                    cout<<"=";
            }
            cout<<endl;
        }

        return;
    }
    for(int i = 0;i < 9;++i)
    {
        if(book[i] == 0)
        {
            book[i] = 1;
            a[step] = i + 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
}

int main()
{
    dfs(0);
    return 0;
}


