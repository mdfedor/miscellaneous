#include "staticList.h"

#include<iostream>
using namespace std;
int main(){

    MyStaticLinkList myslt;
    myslt.ListInsert(1,111);
    myslt.ListInsert(2,222);
    myslt.ListInsert(3,333);
    myslt.ListInsert(4,444);
    myslt.ListInsert(5,555);
    myslt.ListInsert(6,666);

    cout<<"============================"<<endl;

    myslt.PrintLss();

    myslt.ListDelete(1);
    myslt.PrintLss();
    myslt.ListDelete(1);
    myslt.PrintLss();
    myslt.ListDelete(1);
    myslt.PrintLss();
    myslt.ListDelete(1);
    myslt.PrintLss();
    myslt.ListDelete(1);
    myslt.PrintLss();
    myslt.ListDelete(1);
    myslt.PrintLss();

    cout<<"============================"<<endl;

    myslt.ListInsert(1,1111);
    myslt.PrintLss();
    myslt.ListInsert(1,2222);
    myslt.PrintLss();
    myslt.ListInsert(1,3333);
    myslt.PrintLss();
    myslt.ListInsert(1,4444);
    myslt.PrintLss();
    myslt.ListInsert(1,5555);
    myslt.PrintLss();
    myslt.ListInsert(1,6666);
    myslt.PrintLss();
    myslt.ListInsert(1,7777);
    myslt.PrintLss();

    return 0;
}