#include <iostream>
#include "MyQueue.h"
using namespace std;

int main()
{
    MyQueue *p = new MyQueue(4);
    p->EnQueue(10);
    p->EnQueue(12);
    p->EnQueue(16);
    p->EnQueue(18);
    //p->EnQueue(20);
    p->QueueTraverse();

    int e = 0;
    p->DeQueue(e);
    cout<<e<<endl;
    p->DeQueue(e);
    cout<<e<<endl;
    p->DeQueue(e);
    cout<<e<<endl;
    p->DeQueue(e);
    cout<<e<<endl;

    delete p;
    p = NULL;
    return 0;
}
