#include <iostream>
/*
* ��������ȱ������ȫ��������
*/
using namespace std;
int a[100];
int book[100];
int n;
void dfs(int step);
int main()
{
    cout<<"������һ������(С��100)��"<<endl;
    cin >> n;

    dfs(0);
    return 0;
}

void dfs(int step)
{
    if(step == n)
    {
        for(int i = 0;i < n;++i)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 0;i < n;++i)
    {
        if(book[i] == 0)
        {
            a[step] = i + 1;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
}
