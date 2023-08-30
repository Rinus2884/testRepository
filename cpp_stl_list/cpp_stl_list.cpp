/*
    STL Standard Template Library

        container: 자료구조를 타입에 대해 범용적으로 일반화하여 만들어놓은 것
        iterator: container와 algorithm과 같이 사용할 수 있는 일반화된 포인터
        algorithm: 알고리즘을 타입에 대해 범용적으로 일반화하여 만들어놓은 것


*/

#include <iostream>
#include <list>//<-- double linked list를 만들어놓은 것이다.
using namespace std;

class CUnit
{
private:
    int mVal = 0;

public:
    //매개변수 있는 생성자
    CUnit(int t) :mVal(t)
    {

    }

    inline int GetVal()
    {
        return mVal;
    }

    inline void SetVal(int t)
    {
        mVal = t;
    }



};





int main()
{
    //이 예에서는, CUnit타입의 객체의 참조를 원소로 삼겠다.
    list<CUnit*> tUnits;

    CUnit* tpUnit = nullptr;

    //링크드리스트 컨테이너에 유닛들 추가
    //0
    tpUnit = new CUnit(0);
    tUnits.push_back(tpUnit);
    //1
    tpUnit = new CUnit(1);
    tUnits.push_back(tpUnit);

    //2
    tpUnit = new CUnit(2);
    tUnits.push_back(tpUnit);


    //인덱스 접근 연산자를 이용한 랜덤액세스(임의접근)
    //tUnits[0]->GetVal();//<--링크드리스트는 임의접근이 불가능하다

    for (list<CUnit*>::iterator t=tUnits.begin();t!=tUnits.end();++t)
    {
        cout << (*t)->GetVal() << endl;
    }

    //순차검색 O(n)
    for (list<CUnit*>::iterator t = tUnits.begin(); t != tUnits.end(); ++t)
    {
        if (2 == (*t)->GetVal())
        {
            (*t)->SetVal(777);
            break;
        }
    }
    cout << endl;
    //순방향 이터레이터 head ---> tail
    for (list<CUnit*>::iterator t = tUnits.begin(); t != tUnits.end(); ++t)
    {
        cout << (*t)->GetVal() << endl;
    }


    //double linked list이므로 
    //reverse_iterator 역방향 이터레이터도 존재한다. head <--- tail
    cout << endl;
    for (list<CUnit*>::reverse_iterator t = tUnits.rbegin();t!=tUnits.rend();++t)
    {
        cout << (*t)->GetVal() << endl;
    }


    //순회하면서, 임의의 원소 삭제
    //순차검색 O(n)
    for (auto t = tUnits.begin(); t != tUnits.end();)
    {
        if (777 == (*t)->GetVal())
        {
            delete(*t);

           //list의 erase는 다음 이터레이터를 리턴한다.
           t = tUnits.erase(t);
        }
        else
        {
            ++t;
        }
    }


    cout << endl;
    //순방향 이터레이터 head ---> tail
    for (list<CUnit*>::iterator t = tUnits.begin(); t != tUnits.end(); ++t)
    {
        cout << (*t)->GetVal() << endl;
    }



    //모두 삭제
    //원본변수들을 모두 제거한다.
    for (auto t = tUnits.begin();t!= tUnits.end();++t)
    {
        if (nullptr!=(*t))
        {
            delete (*t);
            *t = nullptr;
        }
    }
    //리스트의 원소들을 모두 제거한다.
    tUnits.clear();



    cout << endl;
    cout << "list ---" << endl;
    //순방향 이터레이터 head ---> tail
    for (list<CUnit*>::iterator t = tUnits.begin(); t != tUnits.end(); ++t)
    {
        cout << (*t)->GetVal() << endl;
    }





    return 0;
}

