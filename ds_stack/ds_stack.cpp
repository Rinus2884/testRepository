/*
	스택 자료구조





	스택 stack: LIFO Last Input First Output
			<--가장 나중에 입력된 데이터가 가장 먼저 출력된다
	큐 queue: FIFO  First Input First Output

	<-- '동작명세가 정해져 있는 자료구조'

	<-- 스택이나 큐를 작성할 때, 배열이나 링크드리스트를 이용할 수 있다.


		가장 기본이 되는 자료구조: 배열, 링크드리스트
		기본이 되는 자료구조: 배열, 링크드리스트, 스택, 큐



  여기서는 스택stack을 구현하기 위해 simple linked list를 사용하겠다

*/
#include <iostream>
using namespace std;

struct SNode
{
	int mData = 0;

	SNode* mpNext = nullptr;
};

SNode* mpHead = nullptr;
SNode* mpTail = nullptr;

//스택 기본구조 만들기
void InitStack()
{
	mpHead = new SNode;
	mpTail = new SNode;

	mpHead->mpNext = mpTail;
	mpTail->mpNext = mpTail;
}
void Push(int k)
{
	SNode* s = nullptr;

	//노드 생성
	s = new SNode;

	//데이터 설정
	s->mData = k;

	//링크조작
	s->mpNext = mpHead->mpNext;
	mpHead->mpNext = s;
}
void Pop()
{
	SNode* t = nullptr;

	if (mpHead->mpNext == mpTail)
	{
		cout << "Stack Underflow" << endl;
		return;
	}

	t = mpHead->mpNext;
	mpHead->mpNext = t->mpNext;

	delete t;
}
//스택에 맨 위쪽에 있는 데이터의 값을 얻는다
//음수는 유효하지 않다고 가정하자.
int Top()
{
	int tResult = -1;

	if (mpHead->mpNext == mpTail)
	{
		cout << "Stack Underflow" << endl;
		return tResult;
	}

	SNode* t = nullptr;
	t = mpHead->mpNext;
	tResult = t->mData;


	return tResult;
}
//스택이 비었는지( 스택에 원소가 하나라도 남아있는지 여부 )
bool IsEmpty()
{
	if (mpHead->mpNext == mpTail)
	{
		cout << "Empty" << endl;
		return true;//비어있다(원소가 한개도 없다)
	}
	else
	{
		return false;//비어있지 않다(원소가 한개 이상 존재한다)
	}
}



int main()
{
	InitStack();

	Push(3);
	Push(9);
	Push(777);
	Push(5);
	Push(1);

	while (!IsEmpty())
	{
		int t = Top();
		cout << t << endl;

		Pop();

	}
	
		






	//DestroyStack;
   return 0;
}

