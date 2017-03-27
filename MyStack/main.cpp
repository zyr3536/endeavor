
#include "MyStack.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    MyStack<char> *pStack = new MyStack<char>(100);
    char ch[100];
    char *p = ch;
    cout <<"ÇëÊäÈëÒ»¸öÓÐ()[]{}µÄÀ¨ºÅ±í´ïÊ½£º"<<endl;
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
                    cout << "À¨ºÅ²»Æ¥Åä£¡"<<endl;
                }

            default:
                break;
        }
        p++;
    }
    if(flag)
    {
        if(pStack->stackEmpty())
            cout << "À¨ºÅÆ¥Åä£¡"<<endl;
        else
            cout << "À¨ºÅ²»Æ¥Åä£¡"<<endl;
    }

    delete pStack;
    pStack = NULL;
    return 0;
}
