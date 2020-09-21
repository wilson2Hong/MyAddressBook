#ifndef LIST_H
#define LIST_H

#include<iostream>
#include"Node.h"
using namespace std;


class List
{
public:
    List();
    ~List();
    void ClearList();                                  //清空线性表
    bool ListEmpty();                                  //判断线性表是否为空
    int ListLength();                                  //获取线性表的长度
    bool GetElem(int i,Node *pNode);                             //获取指定元素
    int LocateElem(Node *pNode);                          //寻找第一个满足e的数据元素的位序
    bool PriorElem(Node *currentElem, Node *preElem);  //获取指定元素的前驱
    bool NextElem(Node *currentElem, Node *nextElem);  //获取指定元素的后驱
    bool ListInsert(int i, Node *pNode);                   //在第i个位置插入元素
    bool ListDelete(int i, Node *pNode);                   //在删除第i个位置的元素
    void ListTraverse();                 //遍历线性表
    bool ListInsertHead(Node *pNode);               //头插法
    bool ListInsertTail(Node *pNode);               //尾插法



private:

    Node *m_pList;
    int m_iLength;


};

#endif // LIST_H
