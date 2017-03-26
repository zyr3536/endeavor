#ifndef MYQUEUE_H
#define MYQUEUE_H

/*
*环形队列
*/
class MyQueue
{
    public:
        MyQueue(int queueCapacity);
        virtual ~MyQueue();
        void ClearQueue();
        bool QueueEmpty() const;
        bool QueueFull() const;
        int QueueLength() const;
        bool EnQueue(int element);
        bool DeQueue(int &element);
        void QueueTraverse();

    private:
        int *m_pQueue;  //队列数组指针
        int m_iQueueLen;//队列元素个数
        int m_iQueueCapacity;//队列数组容量
        int m_iHead;//队头
        int m_iTail;//队尾
};

#endif // MYQUEUE_H
