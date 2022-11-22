
/*
 C스타일 원시 배열
     장점:
        i)물리적으로 연속된 메모리 블럭이다.
        ii)객체가 아니라 객체 처리비용( 생성자나 소멸자 등 )이 없다.
        ii)위 사항들에 의해 접근 속도가 빠르다.
     단점:
        i)컴파일시 크기가 고정된다.
        ii)배열의 이름은 상수포인터로 취급되므로 묵시적 타입 변환 등이 가능해 보안상 문제가 될 수도 있다.

 STL의 vector 컨테이너
     장점:
        i)크기가 가변적이다.
        ii)STL의 알고리즘 적용이 가능하다.
     단점:
        i)물리적으로 연속된 메모리 블럭이라고 보장할 수 없다.
        ii)객체라서 객체 처리비용( 생성자나 소멸자 등 )이 있다.
        iii)위 사항들에 의해 접근 속도가 느릴 수도 있다.

CPP스타일 배열
    장점:
        i)STL의 알고리즘 적용이 가능하다.
        ii)물리적으로 연속된 메모리 블럭이다. 즉, 접근속도가 비교적 빠르다.( CPU의 캐쉬 적중률이 높다 )
        iii)생성자, 소멸자, 복사 생성자, 대입 연산자 등의 객체스러움을 제공한다.
        iv)초기화 리스트가 배열의 크기보다 작으면 나머지 원소들은 0으로 초기화하므로 보다 안전하다.
        v)묵시적 형변환을 허용하지 않는다.
 */
#include <iostream>
#include <array>//cpp11에서 추가된 array

using namespace std;

int main()
{
    //cpp11에서 추가된 array
    array<int, 5> tArray = { 1,2,3 };

    //cpp11에서 추가된 for
    //표현에는 드러나지 않지만, '순회'동작은 자동으로 일어난다.
    for (auto tE : tArray)
    {
        cout << tE << endl;
    }

    //배열의 길이를 알 수 있는 멤버함수도 제공한다 
    int tSize = tArray.size();
    cout << "size: " << tSize << endl;

    //iterator와 사용이 가능하다.
    for (auto tItor = tArray.begin(); tItor != tArray.end(); ++tItor)
    {
        cout << (*tItor) << endl;
    }

    //모든 원소들에 값을 주어진 값으로 채운다.
    tArray.fill(777);

    for (auto tItor = tArray.cbegin(); tItor != tArray.cend(); ++tItor)
    {
        cout << (*tItor) << endl;
    }

    //주어진 인덱스의 원소에 접근 멤버함수
    tArray.at(3) = 6;
    cout << tArray.at(3) << endl;

    for (auto tItor = tArray.cbegin(); tItor != tArray.cend(); ++tItor)
    {
        cout << (*tItor) << endl;
    }

    //기존 배열의 인덱스 접근 연산자 표현도 지원한다 
    tArray[0] = 999;

    for (auto tItor = tArray.cbegin(); tItor != tArray.cend(); ++tItor)
    {
        cout << (*tItor) << endl;
    }

    //배열의 처음 원소 값 얻기 , 
    //배열의 마지막 원소 값 얻기 
    cout << tArray.front() << ", " << tArray.back() << endl;





    cout << endl << endl;

    //포인터 변수와 형변환 비교 
    int tArrayC[5] = { 0 };
    for (auto tE : tArrayC) //원시배열과도 작동한다 
    {
        cout << tE << endl;
    }

    int* tpPtrC = nullptr;

    //C스타일 배열은 다음과 같은 형변환이 허용된다.
    tpPtrC = tArrayC;



    //cpp11에 추가된 배열의 경우 
    int* tpPtrD = nullptr;
    array<int, 5> tArrayD = { 1,2,3 };
    
    //Cpp11 배열은 다음과 같은 형변환이 허용되지 않는다 
    //tpPtrD = tArrayD;
    //tpPtrD = (int*)tArrayD;

    //해당 표현을 위해 data멤버함수를 제공한다.
    tpPtrD = tArrayD.data();



    

    return 0;
}

