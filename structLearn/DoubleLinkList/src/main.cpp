#include<iostream>
#include"DoubleLinkList.h"
using namespace std;

void int_test();
void object_test();
int main(){


    int_test();
    object_test();
    return 0;
}


void int_test()
{
    cout << "\n----int_test----" << endl;
    DoubleLinkList<int>* pdlink=new DoubleLinkList<int>();
    pdlink->insert(0,20);
    pdlink->append_last(10);
    pdlink->insert_first(30);
    pdlink->insert(1,50);
    pdlink->insert(2,60);

    cout<<"is_empty()="<<pdlink->is_empty()<<endl;
    cout<<"size()="<<pdlink->size()<<endl;
    int sz=pdlink->size();
    for(int i=0;i<sz;i++)
        cout<<"pdlink("<<i<<")="<<pdlink->get(i)<<endl;
}



struct  stu
{
    int id;
    char name[20];
};

static stu arr_stu[]={
    {10,"aaa"},
    {20,"bbb"},
    {30,"ccc"},
    {40,"ddd"},
};


void object_test()
{
    cout << "\n----int_test----" << endl;
    DoubleLinkList<stu>* pdlink=new DoubleLinkList<stu>();
    pdlink->insert(0,arr_stu[1]);
    pdlink->append_last(arr_stu[0]);
    pdlink->insert_first(arr_stu[2]);

    int sz=pdlink->size();
    struct stu p;
    for(int i=0;i<sz;i++){
        p=pdlink->get(i);
        cout<<"pdlink("<<i<<")=["<<p.id<<", "<<p.name<<"]"<<endl;
    }
}