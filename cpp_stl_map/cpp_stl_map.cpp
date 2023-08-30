/*
    STL container



    map

    이진탐색트리 를 
    컨테이너로 만들어둔 것이다.

        이진탐색트리 BinarySearchTree

        i) 이진트리 binary tree
        ii) 중복된 값을 허용하지 않는다
        iii) 왼쪽 서브트리의 값들을 루트의 값보다 작고, 오른쪽 서브트리의 값들을 루트의 값보다 크다.
        iv) 서브트리도 이진탐색트리



*/
#include <iostream>
#include <map>//<-- map 컨테이너를 사용하기 위해 포함
using namespace std;

int main()
{
    //중복된 값을 허용하지 않는 이진탐색트리의 단점을 보완하기 위해
    //;키:값; 쌍의 데이터를 보관한다.(키: 검색용 데이터, 값: 실제 보관하려는 데이터)
    map<int,string> tMap;


    //추가
    //insert함수를 사용한다
    tMap.insert(make_pair(100, "One Hundred"));//make_pair 키:값쌍의 데이터를 만든다.
    tMap.insert(make_pair(3, "Three"));
    tMap.insert(make_pair(150, "One Hundred Fifty"));
    tMap.insert(make_pair(99, "Ninety nine"));


    //순회
    //<--map컨테이너는 중위순회로 순회함을 알 수 있다.
    //   ---> 그래서 마치 정렬된 것처럼 결과가 나온다.( 원소를 추가하면서 정렬이 되었다 )
    for (map<int,string>::iterator t = tMap.begin();t!=tMap.end();++t)
    {
        cout << "Key: " << t->first << ", ";
        cout << "Value: " << t->second << endl;
    }

    //중복된 키는 무시한다.
    //중복된 키를 허용하지 않는다<--이진탐색트리의 성질 
    tMap.insert(make_pair(99,"abcdefg"));

    cout << endl;
    for (map<int, string>::iterator t = tMap.begin(); t != tMap.end(); ++t)
    {
        cout << "Key: " << t->first << ", ";
        cout << "Value: " << t->second << endl;
    }

    //연관 배열: 배열처럼 표기하지만 실제 배열은 아니다.
    //map은 인덱스 접근 연산자를 사용가능하다.
    //다만, 인덱스 접근 연산자에 들어가는 것은 바로 '키'이다.
    
    cout <<"키 3인 원소의 값: "<< tMap[3] << endl;

    //키가 없는 것은 연관배열 표기시 에러를 내지 않는다
    //그냥 새로운 원소를 만든다. <----------- 그러므로 반드시 주의해야 한다.
    cout << "키 4인 원소의 값: " << tMap[4] << endl;


    cout << endl;
    for (map<int, string>::iterator t = tMap.begin(); t != tMap.end(); ++t)
    {
        cout << "Key: " << t->first << ", ";
        cout << "Value: " << t->second << endl;
    }

    //연관배열 표기를 이용하여 키:값 쌍의 데이터를 추가하고 배정할 수도 있다.
    tMap[123] = "OneHundred Twenty Three";

    cout << endl;
    for (map<int, string>::iterator t = tMap.begin(); t != tMap.end(); ++t)
    {
        cout << "Key: " << t->first << ", ";
        cout << "Value: " << t->second << endl;
    }

    //이 구문( find멤버함수 )은 키를 검색대상으로 하므로
    //이진탐색트리의 검색속도를 낸다
    //그러므로 검색속도( 시간복잡도는 ) 
    // O(log n)이다.
    map<int, string>::iterator tItor = tMap.find(123);
    if (tItor!=tMap.end())
    {
        //검색성공
        tMap.erase(tItor);

    }

    cout << endl;
    for (map<int, string>::iterator t = tMap.begin(); t != tMap.end();++t)
    {
        cout << "Key: " << t->first << ", ";
        cout << "Value: " << t->second << endl;
    }

    //값
    //순차검색, 시간복잡도 O(n)
    for (auto t = tMap.begin(); t != tMap.end();)
    {
        if ("Three" == t->second)
        {
            //map의 erase는 다른 컨테이너와는 다르게 동작한다.
            //다음의 관용구로 사용한다
            tMap.erase(t++);
        }
        else
        {
            ++t;
        }
    }

    cout << endl;
    for (map<int, string>::iterator t = tMap.begin(); t != tMap.end();++t)
    {
        cout << "Key: " << t->first << ", ";
        cout << "Value: " << t->second << endl;
    }


    //모든 원소를 제거한다.
    tMap.clear();


    cout << endl;
    cout << "tMap---------" << endl;
    for (map<int, string>::iterator t = tMap.begin(); t != tMap.end(); ++t)
    {
        cout << "Key: " << t->first << ", ";
        cout << "Value: " << t->second << endl;
    }




    return 0;
}


