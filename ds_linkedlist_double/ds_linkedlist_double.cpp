/*
    double linked list
    양방향 연결 리스트



    링크드리스트의 특징<-- 구조에서 나온 것이다.
    :노드가 데이터와 링크를 가지고, 각각의 링크에 의해 선형으로 연결되어 있는 자료구조

    장점
       i) 실행중에 자료구조의 크기를 번경가능하다
       ii) 자료를 추가하거나 삭제하는데 걸리는 시간이 일정하다 0(1)
       (왜냐하면, 링크를 연결하거나 끊는 것에 의해 구현하기 때문이다)


    단점
        i) 임의접근(random access)이 불가능하다
        ii) 검색에 시간이 오래 걸릴 수도 있다.


*/
#include <iostream>
using namespace std;

//노드
struct SNode
{
    int mData = 0;

   SNode* mpPrev = nullptr; //Head <-- Tail
   SNode* mpNext = nullptr; //Head --> Tail
   
};

SNode* mpHead = nullptr;
SNode* mpTail = nullptr;

//기본구조 구축
void InitList()
{
   mpHead = new SNode;
   mpTail = new SNode;


   //링크조작
   mpHead->mpNext = mpTail;
   mpHead->mpPrev = mpHead;

   mpTail->mpNext = mpTail;
   mpTail->mpPrev = mpHead;


}
//추가 <-- Head 다음에 추가로 가정한다.
SNode* Insert(int k)
{
    SNode*t = nullptr;

    t = new SNode;


    //데이터 설정
    t->mData = k;


    //링크조작 <-- 링크드리스트의 구조 유지
    mpHead->mpNext->mpPrev = t;
    t->mpNext = mpHead->mpNext;
    mpHead->mpNext = t;
    t->mpPrev = mpHead;

    return t;
}

//검색 <-- 링크를 따라가며 검색한다.
SNode* FindNode(int k)
{
    SNode* t = nullptr;

    t = mpHead->mpNext;

    while (t->mData != k && t != mpTail)
    {

        t = t->mpNext;
    }

    return t;
}

//삭제
void Delete(SNode* t)
{
    t->mpPrev->mpNext = t->mpNext;
    t->mpNext->mpPrev = t->mpPrev;

    delete t;
}

void Display(SNode* t)
{
    while (t != mpTail)
    {
        cout << "\t" << t->mData;
        t = t->mpNext;
    }


}


int main()
{
    InitList();

    Insert(10);
    Insert(3);
    Insert(99);

    Display(mpHead->mpNext);


    cout << endl;


    SNode* t = FindNode(3);

    Delete(t);

    Display(mpHead->mpNext);

    cout << endl;

    Insert(7);
    Display(mpHead->mpNext);

    SNode* tt = FindNode(10);

    Delete(tt);
    cout << endl;
    Display(mpHead->mpNext);


    //DestroyList 생략

    return 0;

}

