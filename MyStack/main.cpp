
#include "MyStack.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    MyStack<char> *pStack = new MyStack<char>(100);
    char ch[100];
    char *p = ch;
    cout <<"������һ����()[]{}�����ű��ʽ��"<<endl;
    gets(ch);
    char match;
    bool flag = true;
    while(*p && flag == true)
    {
        switch(*p)
        {
            case '{':
            case '[':
            case '(':
               pStack -> push(*p);break;
            case '}':
            case ']':
            case ')':
                pStack -> pop(match);
                if((*p == '}' && match == '{') || (*p == ')' && match == '(') || (*p == ']' && match == '['))
                    break;
                else
                {
                    flag = false;
                    cout << "���Ų�ƥ�䣡"<<endl;
                }

            default:
                break;
        }
        p++;
    }
    if(flag)
    {
        if(pStack->stackEmpty())
            cout << "����ƥ�䣡"<<endl;
        else
            cout << "���Ų�ƥ�䣡"<<endl;
    }

    delete pStack;
    pStack = NULL;
    return 0;
}
