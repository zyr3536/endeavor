#include "Tree.h"

Tree::Tree(int size)
{
    m_pTree = new int[size];
    m_iSize = size;
    if(int i = 0; i < size; ++i)
        m_pTree[i] = 0;
}

Tree::~Tree()
{
    //dtor
    delete[] m_pTree;
    m_pTree = NULL;
}

int *Tree::SearchNode(int nodeIndex)
{
    if(nodeIndex < 0 || nodeIndex >= m_iSize)
        return NULL;

    return &m_pTree[nodeIndex];
}

bool Tree::AddNode(int nodeIndex,int direction,int *pNode)
{

}
