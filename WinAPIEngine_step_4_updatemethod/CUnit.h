#pragma once



class CAPIEngine;

//���Ӽ��迡 �����ϴ� ���ӿ�����Ʈ�� ��Ÿ���� Ŭ����
class CUnit
{
public:
	//�������� 2���� ���踦 ����
	//<-- ������ �ΰ�
	//<-- float Ÿ������ ����
	float mX = 0.0f;
	float mY = 0.0f;

	//�ϴ�, ���ӿ�����Ʈ�� �ܰ��� ������ ���
	float mRadius = 0.0f;


public:
	CUnit();
	~CUnit();

	//���������
	CUnit(const CUnit& t);
	//���� ���� ������
	void operator=(const CUnit& t);


	//������ �ܰ��� ȭ�鿡 ����ϴ� �Լ�
	void Render(CAPIEngine* tpEngine);



};

