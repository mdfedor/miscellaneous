#include "LinkList.h"


void Test1();
void Test2();
void Test3();
void Test4();

int main(){

    //Test1();
    //Test2();
    //Test3();
    Test4();

    return 0;
}

void Test1()
{//尾插尾删
	SLinkList S;
	S.PushBack(1);
	S.PushBack(2);
	S.PushBack(3);
	S.PushBack(4);
	S.PrintSList();
	S.PopBack();
	S.PrintSList();
	//S.PopBack();
	//S.PopBack();
	//S.PrintSList();
	//S.PopBack();
	//S.PopBack();
	//S.PopBack();
	// SLinkList S1(S);
	// S1.PrintSList();

	// SLinkList S2;
	// S2 = S;
	// S2.PrintSList();
}

void Test2()
{//头插头删
	SLinkList S;
	S.PushFront(1);
	S.PushFront(2);
	S.PushFront(3);
	S.PushFront(4);
	S.PrintSList();
	S.PopFront();
	S.PrintSList();

	S.PopFront();
	S.PopFront();
	S.PopFront();
	S.PrintSList();
	S.PopFront();
}

void Test3()
{//指定位置插入某数，查找某数
	SLinkList S;
	S.PushBack(1);
	S.PushBack(2);
	S.PushBack(4);
	S.PushBack(5);
	S.PrintSList();
	//S.Insert(3, 3);
	SListNode* p = S.Find(4);
	S.Insert(p, 3);
	S.PrintSList();
}

void Test4()
{//删除某结点
	SLinkList S;
	S.PushBack(1);
	S.PushBack(2);
	S.PushBack(3);
	S.PushBack(10);
	S.PushBack(4);
	S.PushBack(5);
	S.PrintSList();

	SListNode* p = S.Find(10);
	S.Erase(p);
	S.PrintSList();
}
