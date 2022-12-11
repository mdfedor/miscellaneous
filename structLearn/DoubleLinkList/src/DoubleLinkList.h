#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H

using namespace std;
template<class T>
struct DNode
{
    T value;
    DNode *prev;
    DNode *next;
    DNode(){}
    DNode(T t,DNode *prev,DNode *next){
        this->value=t;
        this->prev=prev;
        this->next=next;
    }
};


template<class T>
class DoubleLinkList
{
    public:
        DoubleLinkList();
        ~DoubleLinkList();
        int size();
        int is_empty();

        T get(int index);
        T get_first();
        T get_last();

        int insert(int index,T t);
        int insert_first(T t);
        int append_last(T t);

        int del(int index);
        int delete_first();
        int delete_last();

    private:
        int count;
        DNode<T> *phead;
        DNode<T> *get_node(int index);
};




#endif

template <class T>
inline DoubleLinkList<T>::DoubleLinkList():count(0)
{
    phead=new DNode<T>();
    phead->prev=phead->next=phead;
}

template <class T>
inline DoubleLinkList<T>::~DoubleLinkList()
{
    DNode<T>* ptmp;
    DNode<T>* pnode=phead->next;
    while (pnode!=phead)
    {
        ptmp=pnode;
        pnode=pnode->next;
        delete ptmp;
    }
    delete phead;
    phead=nullptr;
}

template <class T>
inline int DoubleLinkList<T>::size()
{
    return count;
}

template <class T>
inline int DoubleLinkList<T>::is_empty()
{
    return 0==count;
}

template <class T>
inline T DoubleLinkList<T>::get(int index)
{
    return get_node(index)->value;
}

template <class T>
inline T DoubleLinkList<T>::get_first()
{
    return get_node(0)->value;
}

template <class T>
inline T DoubleLinkList<T>::get_last()
{
    return get_node(count-1)->value;
}

template <class T>
inline int DoubleLinkList<T>::insert(int index, T t)
{
    if(index==0)
        return insert_first(t);
    DNode<T>* pindex=get_node(index);
    DNode<T>* pnode=new DNode<T>(t,pindex->prev,pindex);
    pindex->prev->next=pnode;
    pindex->prev=pnode;
    count++;
    return 0;
}

template <class T>
inline int DoubleLinkList<T>::insert_first(T t)
{
    DNode<T>* pnode=new DNode<T>(t,phead,phead->next);
    phead->next->prev=pnode;
    phead->next=pnode;
    count++;
    return 0;
}

template <class T>
inline int DoubleLinkList<T>::append_last(T t)
{
    DNode<T>* pnode=new DNode<T>(t,phead->next,phead);
    phead->prev->next=pnode;
    phead->prev=pnode;
    count++;
    return 0;
}

template <class T>
inline int DoubleLinkList<T>::del(int index)
{
    DNode<T>* pindex=get_node(index);
    pindex->next->prev=pindex->prev;
    pindex->prev->next=pindex->next;
    delete pindex;
    count--;
    return 0;
}

template <class T>
inline int DoubleLinkList<T>::delete_first()
{
    return del(0);
}

template <class T>
inline int DoubleLinkList<T>::delete_last()
{
    return del(count-1);
}

template <class T>
inline DNode<T> *DoubleLinkList<T>::get_node(int index)
{
    if(index<0||index>=count)
    {
        cout<<"out of bound!"<<endl;
        return nullptr;
    }
    if(index<=count/2)
    {
        int i=0;
        DNode<T>* pindex=phead->next;
        while (i++<index)
        {
            pindex=pindex->next;
        }
        return pindex;
    }
    int j=0;
    int rindex=count-index-1;
    DNode<T>* prindex=phead->prev;
    while (j++<rindex)
    {
        prindex=prindex->prev;
    }
    return prindex;
}
