#ifndef _STATICLIST_H
#define _STATICLIST_H
#define MAXSIZE 1000
#define ELEMTYPE int
typedef struct staticLinkList
{
    ELEMTYPE data;
    int cur;    
}Component,StaticLinkList[MAXSIZE];

class MyStaticLinkList{
    private:
        StaticLinkList sList;

    public:
        MyStaticLinkList();

    public:
        void InitList();
        int Malloc_SLL();
        bool ListInsert(int i,ELEMTYPE e);
        int ListLength();
        void PrintLss();
        bool ListDelete(int i);
        void Free_SLL(int k);
};
#endif
