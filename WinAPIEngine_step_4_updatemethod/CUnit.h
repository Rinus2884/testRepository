#pragma once



class CAPIEngine;

//게임세계에 존재하는 게임오브젝트를 나타내는 클래스
class CUnit
{
public:
	//연속적인 2차원 세계를 가정
	//<-- 성분이 두개
	//<-- float 타입으로 결정
	float mX = 0.0f;
	float mY = 0.0f;

	//일단, 게임오브젝트의 외관은 원으로 취급
	float mRadius = 0.0f;


public:
	CUnit();
	~CUnit();

	//복사생성자
	CUnit(const CUnit& t);
	//복사 대입 연산자
	void operator=(const CUnit& t);


	//유닛의 외관을 화면에 출력하는 함수
	void Render(CAPIEngine* tpEngine);



};

