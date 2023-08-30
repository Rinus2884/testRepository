/*
    큐자료구조



    스택: LIFO
    큐: FIFO  First Input First Output
       <-- 먼저 입력된 데이터가 먼저 출력된다.



    여기서는 큐를
    링크드리스트로 작성하겠다.
    그 중에서도 더블링크드리스트로 작성한다.
    <-- 왜냐하면 심플링크드리스트로 만드는 경우, 
     데이터를 put 하는 동작을 만드는데 매우 비효율적이기 때문이다.
     (왜냐하면 head쪽에서 접근을 하고 꼬리부분까지 링크를 따라가야하기 때문이다)

    
*/
#include <iostream>
using namespace std;


struct SNode
{
    int mData = 0;

    SNode* mpPrev = nullptr; //Head <-- Tail
    SNode* mpNext = nullptr; //Head --> Tail

};


SNode* mpHead = nullptr;
SNode* mpTail = nullptr;


//큐 기본 구조 만들기
void InitQueue()
{
    mpHead = new SNode;
    mpTail = new SNode;


    //링크조작
    mpHead->mpNext = mpTail;
    mpHead->mpPrev = mpHead;

    mpTail->mpNext = mpTail;
    mpTail->mpPrev = mpHead;

}
//rear에 데이터를 추가한다
void Put(int k)
{
    SNode* t = nullptr;

    t = new SNode;


    //데이터 설정
    t->mData = k;


    //링크조작 <-- 링크드리스트의 구조 유지
    mpTail->mpPrev->mpNext = t;
    t->mpPrev = mpTail->mpPrev;
    mpTail->mpPrev = t;
    t->mpNext = mpTail;
}
//음수는 유효하지 않다고 가정
int Get()
{
    int tResult = -1;
    SNode* t = nullptr;

    t = mpHead->mpNext;

    if (t == mpTail)
    {
        cout << "Queue Underflow" << endl;
        return tResult;
    }

    tResult = t->mData;
    mpHead->mpNext = t->mpNext;
    t->mpNext->mpPrev = mpHead;


    delete t;

    return tResult;
}

bool IsEmpty()
{
    if (mpHead->mpNext == mpTail)
    {
        cout << "Empty" << endl;
        return true;//비어있다.
    }
    else
    {
        return false;//비어있지 않다.
        
    }

}

int main()
{
    InitQueue();


    Put(5);
    Put(7);
    Put(99);

    while (!IsEmpty())
    {
        int t = Get();

        cout << t << endl;
    }




    return 0;
}
