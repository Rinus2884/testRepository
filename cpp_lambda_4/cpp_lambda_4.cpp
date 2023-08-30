/*


    i) 쌩 제어구조

        이해하기 쉽다
        코드 규모가 커질수록, 관리가 불편해지고 버그 가능성이 높아진다.

    ----------------------callable호출가능한 것들

    ii) 함수
        
        (쌩 제어구조에 비해)관리가 편리해진다.
        함수호출 비용이 있다. <-- 그러므로 그만큼 속도가 느려진다


    iii) 인라인 함수

        (쌩 제어구조에 비해)관리가 편리해진다. <-- 코드표기법상 함수이다.
        함수호출 비용이 없다. (컴파일 결과물이 쌩제어구조이다) <-- 그러므로 그만큼 속도가 빨라진다
        <-- 단, 인라인 여부는 컴파일러의 결정이다.


    iv) 함수객체
        
        '클래스'로 만든다 (함수호출 연산자를 '연산자 오버로드'하여 만든다) <-- 코드작성 난이도가 비교적 높다
        객체이다 <-- 관리가 편리하다( 데이터와 기능이 클래스 단위로 묶인다 )
                 <-- 객체 처리 비용(생성자, 소멸자 등)이 든다 <-- 그러므로 그만큼 속도가 느려진다

        관련데이터를 기억시켜둘 수 있다.


    v) 람다

        (쌩 제어구조에 비해)관리가 편리해진다.  <-- 변경의 국지화도 일어난다
        함수호출 비용이 없다. (컴파일 결과물이 쌩제어구조이다) <-- 그러므로 그만큼 속도가 빨라진다

        관련데이터를 기억시켜둘 수 있다.


*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    array<int, 5> tArray = {3,2,1,9,10};
    
    //모든 외부변수를 값으로 캡춰
    auto tShowOrigin = [=]()
    {
        cout << "tShow Origin" << endl;

        std::for_each(tArray.begin(), tArray.end(),
            [](int t)
            {
                cout << t << ", ";
            }
        );

        cout << endl;
    };


    //람다함수 객체호출
    tShowOrigin();

    //정렬: 순서 없이 나열된 것을 순서 있게 다시 나열하는 것
    //std::sort의 predicate에서 A<B 오름차순 정렬
    std::sort(tArray.begin(), tArray.end(), std::less<int>());


    //모든 외부변수를 값으로 캡춰
    auto tShowSorted = [=]()
    {
        cout << "tShow Sorted" << endl;

        std::for_each(tArray.begin(), tArray.end(),
            [](int t)
            {
                cout << t << ", ";
            }
        );

        cout << endl;
    };

    //람다함수 객체호출
    tShowSorted();


    //정렬하기 전에 만든 람다함수각체를 호출했다.
    //이 시점에 내는 이 람다함수객체의 결과는
    //정렬되지 않은 결과를 낸다.
    //  <---왜냐하면, '값으로 캡춰'한 것의 결과가 
    //  '람다함수'에 내부적으로 기억되기 때문이다.
    //      <-- 함수 객체가 결과를 멤버변수로 기억하는 특징과 유사하다.
    tShowOrigin();

    
    //tArray의 원소를 직접 출력
    std::for_each(tArray.begin(), tArray.end(),
        [](int t) 
        {
            cout << t << ", ";
        }
    );
    cout << endl;


    return 0;
}

