
#include "List.h"
#include"Node.h"
#include <iostream>
using namespace std;


List::List()
{
    m_pList = new Node;
    //m_pList->data = 0;     //头结点  数据域没有意义
    m_pList->next = NULL;
    m_iLength = 0;
}


List::~List()
{
    ClearList();
    delete m_pList;
    m_pList = NULL;
}

bool List::ListInsertHead(Node *pNode)              //头插法:将一个节点插入到头结点的后面
{
    Node *temp = m_pList->next;        //申请一个零时内存来存放头结点的头指针，必须从堆中申请内存，从栈中申请的话，这个函数用完后就会被回收
    Node *newNode = new Node;          //申请一个节点来存放要插入的节点
    if (newNode == NULL)
    {
        return false;
    }
    newNode->data = pNode->data;
    m_pList->next = newNode;
    newNode->next = temp;     //新节点尾部指向NULL

    m_iLength++;
    return true;
}
bool List::ListInsertTail(Node *pNode)              //尾插法将新节点插入到list的尾部
{
    Node *currentNode = m_pList;
    while (currentNode->next!=NULL)
    {
        currentNode = currentNode->next;
    }
    Node *newNode = new Node;
    if (newNode == NULL)
    {
        return false;
    }
    newNode->data = pNode->data;
    newNode->next = NULL;
    currentNode->next = newNode;
    m_iLength++;
    return true;
}

void List::ClearList()                                  //清空线性表
{
    Node *currentNode = m_pList->next;              //currentNode获取头结点所指的下一位
    while (currentNode != NULL)
    {
        Node *temp = currentNode->next;            //
        delete currentNode;
        currentNode = temp;
    }
    m_pList->next = NULL;
}


bool List::ListEmpty()                                 //判断线性表是否为空
{
    return m_iLength == 0 ? true : false;

}


int List::ListLength()                                  //获取线性表的长度
{
    return	m_iLength;
}


bool  List::GetElem(int i, Node *pNode)                      //获取指定元素
{
    if (i < 0 || i >= m_iLength)
    {
        return false;
    }
    Node *currentNode = m_pList;      //currentNode 赋值为头结点
    //Node *currentNodeBefore = NULL;
    for (int k = 0; k <= i; k++)
    {
        //currentNodeBefore = currentNode;
        currentNode = currentNode->next;

    }
    pNode->data = currentNode->data;
    return true;
}


int  List::LocateElem(Node *pNode)                     //寻找第一个满足e的数据元素的位序
{
    Node *currentNode = m_pList;
    int count = 0;
    while (currentNode!=NULL)
    {
        currentNode = currentNode->next;
        if (currentNode->data == pNode->data)
        {
            return count;
        }
        count++;
    }
    return -1;
}


bool  List::PriorElem(Node *pCurrentNode, Node *pPreNode)  //获取指定元素的前驱
{
    Node *currentNode = m_pList;
    Node *tempNode = NULL;
    while (currentNode != NULL)
    {
        tempNode = currentNode;
        currentNode = currentNode->next;
        if (currentNode->data == pCurrentNode->data)
        {
            if (tempNode == m_pList)
            {
                return false;
            }
            pPreNode->data = tempNode->data;
        }
        return true;
    }
    return false;
}



bool  List::NextElem(Node *pCurrentNode, Node *pNextNode)  //获取指定元素的后驱
{

    Node *currentNode = m_pList;
    while (currentNode != NULL)
    {
        currentNode = currentNode->next;
        if (currentNode->data == pCurrentNode->data)
        {
            if (currentNode == m_pList)
            {
                return false;
            }
            pNextNode->data = currentNode->next->data;
        }
        return true;
    }
    return false;

}


bool  List::ListInsert(int i, Node *pNode)                   //在第i个位置插入元素
{
    if (i<0 || i>m_iLength)
    {
        return false;
    }
    Node *currentNode = m_pList;
    for (int k = 0; k < i; k++)
    {
        currentNode = currentNode->next;
    }
    Node *newNode = new Node;
    if(newNode==NULL)
    {
        return false;
    }
    newNode->data = pNode->data;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return true;
}


bool  List::ListDelete(int i, Node *pNode)                   //在删除第i个位置的元素,并把删除元素的值通过pNode返回出来
{
    if (i < 0 || i >= m_iLength)
    {
        return false;
    }
    Node *currentNode = m_pList;
    Node *currentNodeBefore = NULL;
    for (int k = 0; k <= i; k++)
    {
        currentNodeBefore = currentNode;
        currentNode = currentNode->next;     //循环结束：currentNode为待删除的节点，currentNodeBefore为待删除节点的前一位
    }
    currentNodeBefore->next = currentNode->next;  //currentNodeBefore指向删除节点后的节点
    pNode->data = currentNode->data;
    delete currentNode;                       //删除节点
    currentNode = NULL;
    m_iLength--;
    return true;
}

void  List::ListTraverse()                 //遍历线性表s
{
    Node *currentNode = m_pList;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        currentNode->printNode();
    }
    cout<<"----------"<<endl;

}






