#ifndef MYQUEUE_H
#define MYQUEUE_H

/*
*���ζ���
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
        int *m_pQueue;  //��������ָ��
        int m_iQueueLen;//����Ԫ�ظ���
        int m_iQueueCapacity;//������������
        int m_iHead;//��ͷ
        int m_iTail;//��β
};

#endif // MYQUEUE_H
