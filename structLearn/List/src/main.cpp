
#include<iostream>
#include "mylist.h"

using namespace std;

void printList(mylist &list,const char* str);

int main(){
    mylist lst;

    //插入
    lst.insertElement(0,10);
    lst.insertElement(1,20);
    lst.insertElement(2,30);
    lst.insertElement(3,40);
    printList(lst,"线性表的值:");
    lst.insertElement(2,60);
    printList(lst,"下标2处插入值后线性表的值:");
    lst.insertElement(5,70);  
    printList(lst,"下标5处插入值后线性表的值:"); 
    if(lst.insertElement(7,80)){
        printList(lst,"下标7处插入值后线性表的值:");
    }else{
        cout<<"插入线性表失败"<<endl;
    }

    //删除
    int ret=0;
    if(lst.delElement(1,&ret)){
        cout<<"删除的元素为:"<<ret<<endl;
    }else{
        cout<<"删除失败"<<endl;
    }
    printList(lst,"删除后线性表的值:"); 
    //查找是否存在元素
    int existIndex=0;
    if(lst.locateElem(40,&existIndex)){
        cout<<"存在该元素下标为:"<<existIndex<<endl;
    }else{
        cout<<"不存在该元素"<<endl;
    }
  
    return 0;
}


void printList(mylist &list,const char* str){
    int ret=0;
    cout<<str<<" ";
    for(int i=0;i<list.getLength();i++){
        list.getElement(i,&ret);
        cout<<ret<<" ";
    }
    cout<<endl;
}




