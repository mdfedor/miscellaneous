#include "staticList.h"
#include<iostream>


using namespace std;
MyStaticLinkList::MyStaticLinkList()
{
    InitList();
}

void MyStaticLinkList::InitList()
{
    int i=0;
    for(;i<MAXSIZE-1;i++)
        sList[i].cur=i+1;//每个元素的cur存储指向下一个位置的下标
    sList[MAXSIZE-1].cur=0;//最后一个元素的cur链表的头,也就是头的下标是多少,
}

//
int MyStaticLinkList::Malloc_SLL()
{
    int i=sList[0].cur;//下标0的cur存储下一个空位置的index
    if(sList[0].cur)//这里初始化为1
        sList[0].cur=sList[i].cur;//然后将下一个空闲位置设置到下标0的cur
    return i;
}

//在第i个元素前插入新数据元素e
bool MyStaticLinkList::ListInsert(int i, ELEMTYPE e)
{
    //j是新元素的index
    //k是新插入元素前一个元素的下标
    //l是用来计算k的位置的
    int j,k,l;
    k=MAXSIZE-1;//存储头节点的index
    if(i<1||i>ListLength()+1)
        return false;
    j=Malloc_SLL();//下一个空闲位置index
    if(j)
    {
        sList[j].data=e;
        for(l=1;l<=i-1;l++)
            ////这个是要找要插入位置的前一个元素的cur,比如要在第四个位置前面插入,也就是找到index=3的位置
            k=sList[k].cur;
        //新插入元素的cur要指向它前一个元素指向的下一个元素下标
        //类似链表中插入一个元素,新元素的next是它前一个元素的next
        sList[j].cur=sList[k].cur;
        //最后把前一个元素cur指向新元素的index
        sList[k].cur=j;
        return true;
    }
    return false;
}

int MyStaticLinkList::ListLength()
{
    int j=0;
    int i=sList[MAXSIZE-1].cur;
    while(i){
        i=sList[i].cur;
        j++;
    }
    return j;
}

void MyStaticLinkList::PrintLss()
{
    int index=MAXSIZE-1;
    cout<<"头元素下标:"<<sList[index].cur<<endl;
    cout<<"下一个空闲元素下标"<<sList[0].cur<<endl;
    while (sList[index].cur!=0)
    {
        index=sList[index].cur;
        cout<<sList[index].cur<<" "<<sList[index].data<<endl;
    }
}

bool MyStaticLinkList::ListDelete(int i)
{
    //k是要删的前一个
    //j是要删的
    int j,k;
    if(i<1||i>ListLength())
        return false;
    k=MAXSIZE-1;//头
    for(j=1;j<=i-1;j++)
        k=sList[k].cur;
    j=sList[k].cur;
    //sList[k].cur是要删元素的前一个指向   sList[j].cur是要删元素的下一个位置index
    sList[k].cur=sList[j].cur;
    Free_SLL(j);
    return true;
}

void MyStaticLinkList::Free_SLL(int k)
{
    // k是要删除元素的index sList[0].cur始终指向的是下一个空闲元素的idnex
    //这里把删除的元素的cur指向了之前sList[0].cur
    sList[k].cur=sList[0].cur;
    //然后再把sList[0].cur指向这个删除掉元素的index
    sList[0].cur=k;
}
