/*
	자료구조 data structure: 
	데이터(자료)들을 담는 
	임의의 구조물이다.
	<-- 각각의 자료구조마다
	구조가 다르므로 특성도 다르다.

	배열array: '동일한 타입'의 원소들의 '연속적'인 메모리 블럭


	링크드리스트linked list:
	'노드Node'가 '데이터Data'와 '링크Link'를 가지고
	각각의 링크에 의해
	한줄로('선형linear'으로) 
	'연결'되어있는 자료구조


	<C로 배우는 알고리즘>1,2권 교재 추천
	<C로 배우는 쉬운 자료구조> - 초급용


*/

#include <iostream>
using namespace std;

//노드가 데이터와 링크를 가지고
struct SNode
{
	int mData = 0;					//데이터
	SNode* mpNext = nullptr;		//링크

};

//예시라서 편의상 전역변수로 만들겠다.
SNode* mpHead = nullptr;		//머리
SNode* mpTail = nullptr;		//꼬리


//Simple Linked List의 기본구조 만들기
void InitList()
{
	mpHead = new SNode;
	mpTail = new SNode;

	//링크조작
	mpHead->mpNext = mpTail;
	mpTail->mpNext = mpTail;
}

//DestroyList도 필요하다. 시간관계상 생략



//추가 <-- Head뒤에 추가하는 것을 가정
SNode* Insert(int k)
{
	SNode*s = nullptr;

	//노드 생성
	s = new SNode;

	//데이터 설정
	s->mData = k;

	//링크조작
	s->mpNext = mpHead->mpNext;
	mpHead->mpNext = s;

	return s;
	

}


//삭제
void Delete(SNode* t, SNode* tPrev)
{
	//링크조작
	tPrev->mpNext = t->mpNext;


	delete t;
}








//검색(탐색)
SNode* FindNode(int k, SNode** tPrev)
{
	SNode* t = nullptr;

	t = mpHead->mpNext;

	while (t->mData != k && t!= mpTail)
	{
		*tPrev = t;//이전 노드의 주소를 저장한다.

		t = t->mpNext;

	}



	return t;
}

//링크드리스트를 순회하며 원소의 값 출력
void DisplayList(SNode* t)
{
	while (t != mpTail)
	{
		cout << "\t" << t->mData;
		t = t->mpNext;
	}
}







int main()
{
	InitList();//링크드리스트 기본구조 생성

	Insert(3);
	Insert(7);
	Insert(10);

	DisplayList(mpHead->mpNext);


	SNode* tPrev = nullptr;
	SNode* tFind = FindNode(7, &tPrev);

	if (tFind != mpTail)
	{
		Delete(tFind, tPrev);

	}

	cout << endl;


	DisplayList(mpHead->mpNext);



	Insert(11);

	cout << endl;
	DisplayList(mpHead->mpNext);

	//DestroyList

   return 0;
}

