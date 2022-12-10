#include "LinkList.h"
#include<assert.h>
#include<iostream>


using namespace std;
SLinkList &SLinkList::operator=(SLinkList &s)
{
    swap(_head,s._head);
    swap(_tail,s._tail);
    return *this;
}
void SLinkList::Clear()
{
    SListNode* cur=_head;
    while (cur)
    {
        SListNode* del=cur;
        cur=cur->_next;
        delete del;
        del=NULL;
    }
}
void SLinkList::PushBack(MydataType x) // 尾插
{
    if(NULL==_head){
        _head=new SListNode(x);
        _tail=_head;
    }
    else{
        _tail->_next=new SListNode(x);
        _tail=_tail->_next;
    }
}

void SLinkList::PopBack()//尾删
{
    if(NULL==_head){//空链表
        cout<<"SLinkList is empty!"<<endl;
    }
    else if(_head==_tail){//只有头节点和尾节点
        delete _head;
        _head=_tail=NULL;
    }else{
        SListNode *cur1;
        cur1=_head;
        while (cur1)
        {
            if(cur1->_next==_tail){
                delete _tail;
                _tail=cur1;
                _tail->_next=NULL;
                break;
            }
            cur1=cur1->_next;
        }
        
    }
}

void SLinkList::PushFront(MydataType x) // 头插
{
    SListNode* tmp=_head;
    _head=new SListNode(x);
    _head->_next=tmp;
}

void SLinkList::PopFront()//头删
{
    if(NULL==_head){
        cout<<"SLinkList is empty!"<<endl;
    }
    else if(NULL==_head->_next){
        delete _head;
        _head=NULL;
    }
    else{
        SListNode* tmp=_head->_next;
        delete _head;
        _head=tmp;
    }
}


void SLinkList::Insert(SListNode *pos, MydataType x)
{
    assert(pos);
    SListNode* tmp=_head;
    while (tmp)
    {
        if(NULL==tmp->_next)
            SLinkList::PushFront(x);
        else if(pos==tmp->_next){
            SListNode* cur=new SListNode(x);
            cur->_next=tmp->_next;
            tmp->_next=cur;
            return;
        }
        tmp=tmp->_next;
    }
}

void SLinkList::Erase(SListNode *pos)
{
    assert(pos);
    SListNode* tmp=_head;
    while(tmp){
        if(NULL==tmp->_next)
            SLinkList::PopFront();
        else if(pos==tmp->_next){
            SListNode* cur=tmp->_next->_next;
            delete tmp->_next;
            tmp->_next=NULL;
            tmp->_next=cur;
            break;
        }
        tmp=tmp->_next;
    }
}

SListNode *SLinkList::Find(MydataType x)
{
    SListNode* cur=_head;
    while (cur)
    {
        if(x==cur->_data)
            return cur;
        cur=cur->_next;
    }
    return nullptr;
}

void SLinkList::PrintSList()
{
    SListNode *cur=_head;
    while (cur)
    {
        cout<<cur->_data<<"->";
        cur=cur->_next;
    }
    cout<<"NULL"<<endl;
}
