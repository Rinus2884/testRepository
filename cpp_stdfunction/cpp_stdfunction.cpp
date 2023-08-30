/*
	std::function

	호출가능한callable 것들을 모두 다룰 수 있는 간접호출 도구

	<-- cpp 에서는 ()를 붙여서 호출 할 수 있는 것들을
	callable하다고 한다.  대표적인 것은 함수이다.


	<-- 간접호출 도구의 대표적인 것은 함수포인터이다.



*/

#include <iostream>
#include <functional>//<-- std::function을 사용하기 위해
using namespace std;


//함수
void DoAdd(int tA, int tB)
{
	int tResult = tA + tB;
	cout << tResult << endl;
}

class CRyu
{
public:
	void operator()(int tA, int tB)
	{
		int tResult = tA + tB;
		cout << tResult << endl;
	}


};


int main()
{
	//step_0
	//호출 가능한 것들을 호출해봄
	DoAdd(3, 2);//함수를 직접호출

	CRyu tRyu;
	tRyu(3, 2);//함수객체를 호출


	auto tLambda = [](int tA, int tB)
	{
		int tResult = tA + tB;
		cout << tResult << endl;
	};

	tLambda(3, 2);//람다를 호출


	//step_1
	//std::function을 사용하여 간접호출해보자.
	//<-- 템플릿 인자로 '호출가능한 것callable의 signature'를 받는다
	std::function<void(int, int)> tFunc_0 = DoAdd;
	tFunc_0(9, 1);

	std::function<void(int, int)> tFunc_1 = tRyu;
	tFunc_1(2, 1);

	std::function<void(int, int)> tFunc_2 = tLambda;
	tFunc_2(999, 25);


	//step_2
	//std::bind
	//<-- 호출가능한 것들을 객체화하면서,주어진 값들도 각각의 인자argument에 바인드(연동한다, 붙여준다) 한다.

	auto tAddRyu_0 = std::bind(DoAdd, 1, 7);
	tAddRyu_0();//<-- 호출할 때 인자의 값을 명시하지 않으면 바인드된 값을 인자의 값으로 넘긴다


	auto tAddRyu_1 = std::bind(DoAdd, 3, std::placeholders::_1);
	tAddRyu_1(9);


	auto tAddRyu_2 = std::bind(DoAdd, std::placeholders::_1, std::placeholders::_2);
	tAddRyu_2(10,5);




   return 0;
}

