/*
    배열: 동일한 타입의 원소들의 '연속적'인 메모리 블럭

    링크드리스트 linkedlist: '노드'가 '데이터'와 '링크'를 가지고 각각의 링크에 의해 '선형으로(1:1로)' '연결'되어 있는 자료구조

    트리tree: 1:N의 비선형 자료구조
              계층형 자료구조




    이진트리 binary tree: 
    i) 트리여야 한다
    ii) 최대 자식노드의 갯수가 2개 이하
    iii) 자식노드는 Lt. Child Node거나 Rt. Child Node로 만든다.



    이진트리의 순회traverse방법
    i)전위 순회 PreOrder
        root
        lt. subtree
        rt. subtree

    ii)중위 순회 InOrder
        lt. subtree
        root
        rt. subtree

    iii)후위 순회 PostOrder
        lt. subtree
        rt. subtree
        root
    

    <--순회규칙은 트리tree에 적용한다.
    <--'재귀적'으로 작동한다.
    <--최초접근은 '최상단root노드'에서 한다.



    iv)층별(레벨) 순회 level order

    
        층을 타고 내려오면서, 각각의 층에서 Lt ---> Rt 순서로 방문visit





*/
#include <iostream>
#include <queue>//층별 순회를 위해 큐 사용을 하기 위해서다 
//queue <-- FIFO

using namespace std;






//노드
struct SNode
{
    //데이터
    char mData = 0;

    //링크
    SNode* mpLt = nullptr;
    SNode* mpRt = nullptr;
};

std::queue <SNode*> gQueue;

//임의의 루트노드를 만든다.
SNode* MakeRoot(char tData, SNode* tpLt, SNode* tpRt)
{
    SNode* tRoot = nullptr;
    tRoot = new SNode;

    tRoot->mData = tData;
    tRoot->mpLt = tpLt;
    tRoot->mpRt = tpRt;


    return tRoot;
}

//root
//lt.
//rt.
void PreOrder(SNode* tpRoot)
{
    if (nullptr != tpRoot)
    {
        //visit
        cout << tpRoot->mData;

        PreOrder(tpRoot->mpLt);
        PreOrder(tpRoot->mpRt);

    }
}

//lt
//root
//rt.
void InOrder(SNode* tpRoot)
{
    if (nullptr != tpRoot)
    {
        //visit

        InOrder(tpRoot->mpLt);

        cout << tpRoot->mData;

        InOrder(tpRoot->mpRt);

    }
}

//lt
//rt.
//root
void PostOrder(SNode* tpRoot)
{
    if (nullptr != tpRoot)
    {
        //visit

        PostOrder(tpRoot->mpLt);

        PostOrder(tpRoot->mpRt);

        cout << tpRoot->mData;

    }
}

void LevelOrder(SNode* tpRoot)
{
    gQueue.push(tpRoot);


    //원소가 한개라도 있다면 
    while (!gQueue.empty())
    {
        tpRoot = gQueue.front();
        gQueue.pop();


        cout << tpRoot->mData;//visit

        if (nullptr!=tpRoot->mpLt)
        {
            gQueue.push(tpRoot->mpLt);
        }

        if (nullptr != tpRoot->mpRt)
        {
            gQueue.push(tpRoot->mpRt);
        }

    }

}




int main()
{
    //임의의 이진트리binary tree를 만든다
    SNode* N7 = MakeRoot('D', nullptr, nullptr);
    SNode* N6 = MakeRoot('C', nullptr, nullptr);
    SNode* N5 = MakeRoot('B', nullptr, nullptr);
    SNode* N4 = MakeRoot('A', nullptr, nullptr);
    SNode* N3 = MakeRoot('/', N6, N7);
    SNode* N2 = MakeRoot('*', N4, N5);
    SNode* N1 = MakeRoot('-', N2, N3);



    //preorder: -*AB/CD
    cout << "pre order traverse: " << endl;
    PreOrder(N1);
    cout << endl;


    //inorder: A*B-C/D
    cout << "in order traverse: " << endl;
    InOrder(N1);
    cout << endl;


    //postorder: AB*CD/-
    cout << "post order traverse: " << endl;
    PostOrder(N1);
    cout << endl;


    //levelorder: -*/ABCD
    cout << "level order traverse: " << endl;
    LevelOrder(N1);
    cout << endl;





    return 0;
}

