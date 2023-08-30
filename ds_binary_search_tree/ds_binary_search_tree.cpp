/*

    배열: 동일한 타입의 원소들의 연속적인 메모리 블럭



    링크드리스트: 노드가 데이터와 링크를 가지고 각각의 링크에 의해 선형(1:1)으로 연결된 자료구조



    트리 tree: 1:N의 비선형 자료구조
              계층구조



    이진트리 binary tree:
    i) 트리
    ii) 최대자식노드의 갯수가 2개 이하
    iii) Lt.chilnode, Rt. childNode


    
    이진탐색트리 binary search tree
    <--목적: '탐색(검색)을 목적'으로 이진트리를 개조하여 만든 자료구조

    i) 이진트리여야 한다.
    ii) 중복된 값을 허용하지 않는다
    iii) 왼쪽 서브트리의 값은 루트보다 작고, 오른쪽 서브트리의 값은 루트보다 크다
    iv) 서브트리도 이진탐색트리여야 한다





                                                            구조나 특징은 외워야 함
                                                            링크드리스트 : 10000번 이진탐색트리: 14번   log2 만큼 줄어든다
*/
#include <iostream>
using namespace std;

struct SNode
{
    int mData = 0;

    SNode* mpLt = nullptr;
    SNode* mpRt = nullptr;
};

//탐색(검색)
SNode* Search(SNode* tRoot, int tX)
{
    SNode* tpNode = nullptr;

    tpNode = tRoot;
    while (nullptr!=tpNode)
    {
        if (tX == tpNode->mData)
        {
            //검색성공
            return tpNode;
        }
        else if (tX < tpNode->mData)
        {
            //작으면 왼쪽
            tpNode = tpNode->mpLt;
        }
        else if (tX > tpNode->mData)
        {
            //크면 오른쪽
            tpNode = tpNode->mpRt;
        }
    }



    return tpNode;
}
//추가
//<--이진탐색트리의 구조를 유지해야한다.
SNode* Insert(SNode* tRoot, int tX)
{
    SNode* tpNode = nullptr;

    tpNode = tRoot;

    if (nullptr== tRoot)
    {
        //단말에 추가한다.
        tpNode = new SNode;

        tpNode->mData = tX;
        tpNode->mpLt = nullptr;
        tpNode->mpRt = nullptr;
    }
    else if (tX<tRoot->mData)
    {
        //왼쪽으로 탐색하다가, 단말에 추가한다
        tRoot->mpLt= Insert(tRoot->mpLt, tX);
        //<--재귀호출로 구현
    }
    else if (tX > tRoot->mData)
    {
        //오른쪽으로 탐색하다가, 단말에 추가한다
        tRoot->mpRt = Insert(tRoot->mpRt, tX);
        //<--재귀호출로 구현
    }
    else
    {
        //추가하려는 값이 이미 있는 것이다.
        cout << "중복된 값입니다." << endl;
    }

    return tpNode;
}
//삭제
//<--이진탐색트리의 구조를 유지해야한다.
//  차수0, 차수1, 차수2 인 경우를 나누어 처리해야 한다.
void Delete(SNode* tRoot, int tX)
{
    SNode* parent = nullptr, * p = nullptr, * succ = nullptr, * succ_parent = nullptr;
    SNode* child = nullptr;

    parent = nullptr;
    p = tRoot;




    //삭제할 노드를 탐색
    while ((nullptr!=p) && (tX != p->mData))//단말 노드인가? && 찾으려는 데이터인가?
    {
        //타고 내려가기 전의 노드의 주소를 기억시켜둠
        parent = p;

        if (tX < p-> mData)//작으면
        {
            p = p->mpLt;
        }
        else//크면
        {
            p = p->mpRt;
        }
        //같으면은 위에 while 문 조건문에서 처리됨

    }

    if (nullptr == p)
    {
        cout << "찾으려는 값이 이진탐색트리에 없다." << endl;
    }
    //여기까지 오면 노드를 찾은 것이다.



    //case 0
    //차수가 0인 경우 <-- 삭제할 노드가 단말 노드인 경우
    if (nullptr == p->mpLt && nullptr == p->mpRt)//and
    {
        if (nullptr!=parent)
        {
            if (p == parent->mpLt)//왼쪽
            {
                parent->mpLt = nullptr;
            }
            else//오른쪽
            {
                parent->mpRt = nullptr;
            }
        }
        else
        {
            tRoot = nullptr;
        }
       
    }




    //case 1
    //차수가 1인 경우 <-- 삭제할 노드가 자식노드를 한개 가진 경우
    else if (nullptr == p->mpLt || nullptr == p->mpRt)//or
    {

        //현재 root노드의 자식을 기억시켜둔다.
        if (nullptr!= p->mpLt )//왼쪽에 자식이 있다.
        {
            child = p->mpLt;
        }
        else//오른쪽에 자식이 있다.
        {
            child = p->mpRt;
        }


        if (nullptr!= parent)
        {
            if (p == parent->mpLt)//왼쪽
            {
                parent->mpLt = child;//현재 root노드의 부모에 child를 링크
            }
            else//오른쪽
            {
                parent->mpRt = child;//현재 root노드의 부모에 child를 링크
            }
        }
        else
        {
            tRoot = child;
        }

    }



    
    //case 2
    //차수가 2인 경우 <-- 삭제할 노드가 자식노드를 두개 가진 경우
    else
    {
        succ_parent = p;
        succ = p->mpLt;

        while (succ->mpRt != nullptr)
        {
            succ_parent = succ;
            succ = succ->mpRt;

        }

        if (succ_parent->mpLt == succ)
        {
            succ_parent->mpLt = succ->mpLt;
        }
        else
        {
            succ_parent->mpRt = succ->mpLt;
        }

        p->mData = succ->mData;
        p = succ;

    }


    delete p;

}





void DisplayPreOrder(SNode* root)
{
    if (root)
    {
        cout << root->mData << ", ";

        DisplayPreOrder(root->mpLt);
        DisplayPreOrder(root->mpRt);
    }
}
//붙여넣자
void DisplayMenu()
{
    cout << endl << "*---------------------------*";
    cout << endl << "\t1 : 트리 출력";
    cout << endl << "\t2 : 숫자 삽입";
    cout << endl << "\t3 : 숫자 삭제";
    cout << endl << "\t4 : 숫자 검색";
    cout << endl << "\t5 : 종료";
    cout << endl << "*---------------------------*";
    cout << endl << "메뉴입력 >> ";
}

//main은 붙여넣자.
int main(int argc, const char* argv[])
{
    SNode* root = NULL;
    SNode* foundedNode = NULL;
    int tChoice = 0;
    int mData = 0;

    //예시 그림과 맞춰 둔 예시코드이다
    //이러한 순서대로 추가하였으므로 예시 그림과 같은 형태가 된다
    root = Insert(root, 8);
    Insert(root, 3);
    Insert(root, 10);
    Insert(root, 2);
    Insert(root, 5);
    Insert(root, 14);
    Insert(root, 11);
    Insert(root, 16);


    while (1)
    {
        DisplayMenu();

        cin >> tChoice;

        switch (tChoice)
        {
        case 1:
        {
            cout << "\t[이진 트리 출력]  ";
            DisplayPreOrder(root);

            cout << endl;
        }
        break;

        case 2:
        {
            cout << "삽입할 문자를 입력하세요 : ";

            cin >> mData;

            Insert(root, mData);
        }
        break;

        case 3:
        {
            cout << "삭제할 문자를 입력하세요 : ";

            cin >> mData;
            Delete(root, mData);
        }
        break;

        case 4:
        {
            cout << "찾을 문자를 입력하세요 : ";

            cin >> mData;
            foundedNode = Search(root, mData);

            if (foundedNode != NULL)
            {

                cout << endl << foundedNode->mData << "를 찾았습니다! " << endl;
            }
            else
            {

                cout << endl << " 문자를 찾지 못했습니다. " << endl;
            }
        }
        break;

        case 5:
        {
            return 0;
        }

        default:
        {
            cout << "없는 메뉴입니다. 메뉴를 다시 선택하세요! " << endl;
        }
        break;
        }
    }

    return 0;
}

