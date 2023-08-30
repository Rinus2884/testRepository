#include "CUnit.h"

#include "CAPIEngine.h"

CUnit::CUnit()
{
	mX = 400.0f;
	mY = 500.0f;

	mRadius = 30.0f;
}
CUnit::~CUnit()
{

}


CUnit::CUnit(const CUnit& t)
{
	mX = t.mX;
	mY = t.mY;

	mRadius = t.mRadius;
}

void CUnit::operator=(const CUnit& t)
{
	mX = t.mX;
	mY = t.mY;

	mRadius = t.mRadius;
}
//CUnit클래스와 CAPIEngine클래스에 관계를 맺어줬다.
//의존관계 dependency
void CUnit::Render(CAPIEngine* tpEngine)
{
	tpEngine->DrawCircle(mX, mY, mRadius);
}
