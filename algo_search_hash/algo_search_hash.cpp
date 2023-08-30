/*
    해쉬 검색:
    <-- 해쉬 자료구조를 이용한다
       <--해쉬hash: '데이터'가 곧 '위치'가 되는 자료구조

       <--시간복잡도 O(1)
       <--공간복잡도 n



    해쉬 함수: 데이터를 위치로 변환해주는 함수
    <-- 해쉬값( 위치 )을 결과로 낸다
    <-- 빨라야만 한다

    해쉬 테이블: 버킷들에 집합
    버킷: 해쉬값 위치에 있는 통, 슬롯들의 집합
    
    슬롯: 데이터를 담은 곳

    충돌: 서로 다른 데이터가 동일한 버킷주소(해쉬값)를 갖는 것
    오버플로우: 버킷에 슬롯이 가득 찼을 때 또 다시 충돌이 일어나는 경우

    <-- 오버플로우를 해결하는 방법 중 하나로 체이닝(chainging)이 있다.
        <--링크드리스트로 슬롯들을 구성하는 것이다.
*/

/*
    이 예시에서는 버킷의 갯수는 10개,
    오버플로우의 해결은 링크드리스트로 한다(체이닝)
*/
#include <iostream>
using namespace std;

//매크로 상수 정의
#define TABLE_SIZE 10

//체이닝을 이용하기 위해 simeple linked list의 노드를 정의
struct SNode
{
    int mData = 0;
    SNode* mpNext = nullptr;
};


//해쉬 함수: 데이터 --> 버킷의 위치 (해쉬값)
//        십진수의 기수(10)으로 나눈 나머지를 해쉬값으로 삼는다.
int HashFunc(int tData)
{
    int t = -1;
    t = tData% TABLE_SIZE;

    return t;
}

void HashInit(SNode tArray[], int * tpTotalCount, int tLength)
{
    //체이닝 기본 구조 설정
    for (int ti = 0;ti<tLength;++ti)
    {
        tArray[ti].mpNext = nullptr;
    }
    //해쉬테이블에 전체 데이터의 갯수를 0개로 설정
    *tpTotalCount = 0;

}
//해쉬 자료구조 기본 구조 작성
void HashCreate(SNode** tpNode, int* tpTotalCount, int tLength)
{
    //버킷 생성
    *tpNode = new SNode[tLength];


    HashInit(*tpNode, tpTotalCount, tLength);
}


//추가
SNode* HashInsert(int tX, SNode tArray[], int* tpTotalCount)
{
    //버킷을 찾는다.
    //슬롯은 맨 앞에 추가한다

    int tHashIndex = -1; //버킷 인덱스(해쉬값)
    SNode* tpNode = nullptr;
    

    tpNode = new SNode;

    tHashIndex = HashFunc(tX);//데이터가 곧 위치
    //데이터
    tpNode->mData = tX;

    //링크조작
    tpNode->mpNext = tArray[tHashIndex].mpNext;
    tArray[tHashIndex].mpNext = tpNode;


    (*tpTotalCount)++;//원소 갯수 하나 증가

    return tpNode;
}


//삭제
SNode* HashDelete(int tX, SNode tArray[], int* tpTotalCount)
{
    //전체원소의 갯수가 0보다 커야 지운다


    //버킷을 찾는다.
    //링크드리스트를 순회한다

    

    if (*tpTotalCount>0)
    {
        //노드 검색과 링크 조작에 필요한 지역변수
        SNode* tpPtr = nullptr;
        SNode* tpNode = nullptr;

        int tHashIndex = HashFunc(tX);
        //O(1)
        tpPtr = &tArray[tHashIndex];//임의의 버킷의 주소를 얻는다.

        tpNode = tpPtr->mpNext;

        //O(m)
        //꼬리가 아님 && 찾으려는 값이 아님
        while (nullptr != tpNode && tX != tpNode->mData)
        {
            tpPtr = tpNode;//그 이전노드를 기억

            tpNode = tpNode->mpNext;
        }
        //꼬리까지 왔다. 찾으려는 데이터가 없는 경우
        if (nullptr == tpNode)
        {
            return nullptr;
        }

        //찾은 경우.
        //링크조작
        tpPtr->mpNext = tpNode->mpNext;
        delete tpNode;
        //원소 갯수 감소
        (*tpTotalCount)--;

        return tpPtr;
    }

    return nullptr;
}


//탐색
SNode* HashSearch(int tX, SNode tArray[])
{
    //버킷을 찾는다.
    //링크드리스트를 순회한다


    SNode* tpNode = nullptr;


    int tHashIndex = HashFunc(tX);
    //O(1)
    tpNode = &tArray[tHashIndex];//임의의 버킷의 주소를 얻는다.

    //O(m)
    //꼬리가 아님 && 찾으려는 값이 아님
    while (nullptr!= tpNode && tX!= tpNode->mData)
    {
        tpNode = tpNode->mpNext;
    }

    //검색성공, 또는 검색 실패 둘 중에 하나의 값이 나온다.( nullptr이면 검색실패 )
    return tpNode;
}

void HashListDisplay(SNode tArray[], int tLength)
{
    SNode* tpNode = nullptr;
    //버킷
    for (int ti = 0; ti < tLength; ti++)
    {
        cout << endl << ti << "Bucket : ";

        tpNode = tArray[ti].mpNext;
        //체이닝 chaining
        while (nullptr != tpNode)
        {
            cout << "  -> " << tpNode->mData;

            tpNode = tpNode->mpNext;
        }
    }

    cout << endl;
}



//let's copy and paste
void Interpret(SNode tArray[], int* tpTotalElementCount, int tLength)
{
    cout << "(q: quit, ";
    cout << "i: input, ";
    cout << "l: view, ";
    cout << "s: search, ";
    cout << "d: delete )" << endl;

    char tCommand[2] = { 0,0 };
    char tKey[2] = { 0,0 };

    while (tCommand[0] != 'q')
    {
        cout << endl << "Input command ->";

        cin >> tCommand;

        switch (tCommand[0])
        {
        case 'i':
        case 'I':
        {

            cin >> tKey;

            HashInsert(tKey[0], tArray, tpTotalElementCount);

            cout << "\n   Successful insert.";
        }
        break;
        case 'd':
        case 'D':
        {

            cin >> tKey;

            if (HashDelete(tKey[0], tArray, tpTotalElementCount) == NULL)
            {
                cout << "\n   Error : Table Empty or Can't find";
            }
            else
            {
                cout << "\n   Successful delete.";
            }
        }
        break;
        case 's':
        case 'S':
        {

            cin >> tKey;

            SNode* tpTemp = NULL;
            tpTemp = HashSearch(tKey[0], tArray);

            if (tpTemp == NULL)
            {
                cout << "\n   Error : Can'f find that key";
            }
            else
            {
                cout << "\n   Ok! find in " << tpTemp->mData << " th position";
            }
        }
        break;
        case 'l':
        case 'L':
        {
            HashListDisplay(tArray, tLength);
        }
        break;
        }


        cout << "  n = " << *tpTotalElementCount;
    }
}


int main()
{
    std::cout << "algo_search_hash" << endl;

    SNode* tpTable = nullptr;

    int tTotalElementCount = 0;

    HashCreate(&tpTable, &tTotalElementCount, TABLE_SIZE);

    Interpret(tpTable, &tTotalElementCount, TABLE_SIZE);

    //HashDeleteAll(tpTable, &tTotalElementCount, TABLE_SIZE);


    delete tpTable;

    return 0;
}
