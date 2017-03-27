#ifndef MYSTACK_H
#define MYSTACK_H


template <typename T>
class MyStack
{
    public:
        MyStack(int size);
        virtual ~MyStack();
        bool stackEmpty();
        bool stackFull();
        bool clearStack();
        int stackLength();
        bool push(T element);
        bool pop(T &element);
        void stackTraverse(bool isFromButtom);
    private:
        T *m_pBuffer;//ջ�ռ�ָ��
        int m_iSize;//ջ����
        int m_iTop;//ջ����ջ��Ԫ�ظ���
};

#include <iostream>
using namespace std;
template<typename T>
MyStack<T>::MyStack(int size)
{
    m_iSize = size;
    m_pBuffer = new T[size];
    m_iTop = 0;
}
template<typename T>
MyStack<T>::~MyStack()
{
    delete[] m_pBuffer;
    m_pBuffer = NULL;
}
template<typename T>
bool MyStack<T>::stackEmpty()
{
    if(0 == m_iTop)
        return true;
    return false;
}
template<typename T>
bool MyStack<T>::stackFull()
{
    if(m_iTop == m_iSize)
        return true;
    return false;
}
template<typename T>
bool MyStack<T>::clearStack()
{
    m_iTop = 0;
    return true;
}
template<typename T>
int MyStack<T>::stackLength()
{
    return m_iTop;
}
template<typename T>
bool MyStack<T>::push(T elem)
{
    if(stackFull())
    {
        return false;
    }
    m_pBuffer[m_iTop++] = elem;
    return true;
}
template<typename T>
bool MyStack<T>::pop(T &elem)
{
    if(stackFull())
        return false;
    elem = m_pBuffer[--m_iTop];
    return true;
}
template<typename T>
void MyStack<T>::stackTraverse(bool isFromButtom)
{
    if(isFromButtom)
    {
        for(int i = 0;i < m_iTop;++i)
            cout << m_pBuffer[i];

    }
    else
    {
         for(int i = m_iTop - 1;i >= 0;--i)
            cout << m_pBuffer[i];
    }
}

#endif // MYSTACK_H
