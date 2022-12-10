#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef int MydataType;
class SListNode{
    friend class SLinkList;
    public:
        SListNode(const MydataType data):_next(nullptr),_data(data){}
    private:
        SListNode* _next;
        MydataType _data;
};

class SLinkList{
    public:
        SLinkList():_head(nullptr),_tail(nullptr){}

        SLinkList(const SLinkList& s):_head(nullptr),_tail(nullptr){
            SListNode* cur=s._head;
            while (cur)
            {
                this->PushBack(cur->_data);
                cur=cur->_next;   
            }
        }

        SLinkList& operator=(SLinkList& s);
        ~SLinkList(){Clear();}
    public:
        void Clear();
        void PushBack(MydataType x);
        void PopBack();
        void PushFront(MydataType x);
        void PopFront();
        void Insert(SListNode* pos,MydataType x);
        void Erase(SListNode* pos);
        SListNode* Find(MydataType x);
        void PrintSList();
    private:
        SListNode* _head;
        SListNode* _tail;
};



#endif