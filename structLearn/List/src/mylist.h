#ifndef _MYLIST_H
#define _MYLIST_H

#define ELEMENT int
#define MAXSIZE 20

typedef struct
{
    ELEMENT data[MAXSIZE];
    int Length;
}sqList;


class mylist
{
private:
    sqList mylst;
public:
    mylist():mylst(){};
    ~mylist(){};
public:
    bool getElement(int index,ELEMENT *ret);
    bool insertElement(int index,ELEMENT mydata);
    int getLength(){return mylst.Length;}
    bool delElement(int index,ELEMENT *ret);
    void clearList();
    bool locateElem(ELEMENT dataTmp,int* index);
};



#endif