#include "MyQueue.h"
#include <iostream>
using namespace std;

MyQueue::MyQueue(int queueCapacity)
{
    m_pQueue = new int[queueCapacity];//暂时不判断申请是否成功
    m_iQueueCapacity = queueCapacity;
    ClearQueue();
}

MyQueue::~MyQueue()
{
    delete[] m_pQueue;
    m_pQueue = NULL;
}

void MyQueue::ClearQueue()
{
    m_iQueueLen = 0;
    m_iHead = 0;
    m_iTail = 0;
}

bool MyQueue::QueueEmpty() const
{
    return m_iQueueLen == 0?true:false;
}

int MyQueue::QueueLength() const
{
    return m_iQueueLen;
}

bool MyQueue::QueueFull() const
{
    return m_iQueueCapacity == m_iQueueLen?true:false;
}

bool MyQueue::EnQueue(int element)
{
    if(QueueFull())
        return false;
    else
    {
        m_pQueue[m_iTail] = element;
        m_iTail++;
        m_iTail %= m_iQueueCapacity;
        m_iQueueLen++;
        return true;
    }
}

bool MyQueue::DeQueue(int &element)
{
    if(QueueEmpty())
        return true;
    element = m_pQueue[m_iHead];
    m_iHead++;
    m_iHead %= m_iQueueCapacity;
    m_iQueueLen--;
    return true;
}

void MyQueue::QueueTraverse()
{
    cout<<endl;
    for(int i = 0;i < m_iQueueLen;++i)
    {
        cout<<m_pQueue[(i + m_iHead) % m_iQueueCapacity]<<endl;
    }
    cout<<endl;
}
