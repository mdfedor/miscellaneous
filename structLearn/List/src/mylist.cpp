#include "mylist.h"

//index为下标，而不是第几个元素
bool mylist::getElement(int index, ELEMENT *ret)
{
    bool flag=true;
    if(mylst.Length!=0&&index>=0&&index<mylst.Length)
        *ret = mylst.data[index];
    else
        flag=false;
    return flag; 
}
//
bool mylist::insertElement(int index, ELEMENT mydata)
{
    int tmp=0;
    if(index==MAXSIZE-1||index<0||index>=mylst.Length+1)//超出最大数组长度，超出边界
        return false;
    if(index<mylst.Length){//给要插入的元素空出位置
        for(tmp=mylst.Length-1;tmp>=index;tmp--){
            mylst.data[tmp+1]=mylst.data[tmp];
        }
    }
    mylst.data[index]=mydata;
    mylst.Length++;
    return true;
}
//删除指定下标的元素
bool mylist::delElement(int index,ELEMENT *ret)
{
    if(index==MAXSIZE||index<0||index>=mylst.Length)
        return false;
    *ret=mylst.data[index];
    for(;index<mylst.Length;index++){
        mylst.data[index]=mylst.data[index+1];
    }
    mylst.Length--;
    return true;
}

void mylist::clearList()
{
    mylst.Length=0;
}
//查找某个元素是否存在于线性表中
bool mylist::locateElem(ELEMENT dataTmp,int* index)
{
    int flag=true;
    if(mylst.Length==0){
        flag=false;
    }else{
        for(int i=0;i<mylst.Length;i++){
            if(dataTmp==mylst.data[i]){
                *index=i;
                break;
            }
        }
    }
    return flag;
}
