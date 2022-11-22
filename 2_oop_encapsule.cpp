//
//  main.cpp
//  cpp_oop_encapsulation_0
//
//  Created by pokpoongryu on 2020/03/03.
//  Copyright © 2020 pokpoongryu. All rights reserved.
//

/*
    created by pokpoongryu
 
    OOP의 4가지 특징
 
    추상화 abstraction
 
    은닉화 encapsulation
 
        외부에 멤버변수를 감춘다.
        Data Hiding이라고도 한다.
 
        호출하는 측의 코드를 되도록 수정하지 않게 하는 방법이다.
 
 */



#include <iostream>

using namespace std;


//step_0
class CSlime
{
//public:
private:
    
    int mX     = 0;
    int mHP    = 100;
    int mAP    = 30;
    
    //step_2
    int mStrength = 0;

public:
    CSlime();
    ~CSlime();
    
    void DisplayInfo();
    
    
    //step_1
    void BuildInfo( int tX, int tHP, int tAP );
    
};

//
////step_3
////  임의의 변수에 대해 Getter, Setter 라는 개념이 기본적이다.
//class CBrave
//{
//private:
//    int mX = 0;
//    
//public:
//    int GetX() const;
//    void SetX( int tX );
//    
//    
//    CBrave() {};
//    ~CBrave() {};
//};


class CBrvae
{
private:

    int mX = 0;

public:
    void SetX(int tX); //setter
    int GetX();         //getter



};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "cpp_oop_abstract_0\n";
    
    //step_0
    CSlime tSlime;
    
    //멤버변수를 private로 선언하여
    //이제 외부에서는 접근 불가능하다.
//    tpSlime->mX = 5;
//    tpSlime->mHP = 5000;
//    tpSlime->mAP = 777;
    
    
    //step_1
    //대신 멤버함수를 만들어 멤버변수들을 조작하도록 우회하여 접근한다.
    //( 외부에 멤버변수는 감추고, 멤버함수만 노출한다 )
    //
    tSlime.BuildInfo( 5, 5000, 777 );
    
    
    
    tSlime.DisplayInfo();
    
    
    cout<<endl;
    
    
    //step_3
    CBrave tBrave;
    tBrave.SetX(4);
    
    cout<<"brave x: "<<tBrave.GetX()<<endl;
    
    
    return 0;
}

CSlime::CSlime()
{
    mX     = 0;
    mHP    = 100;
    mAP    = 30;
}

CSlime::~CSlime()
{
    
}


void CSlime::DisplayInfo()
{
//    cout<<"CSlime.mX: "<<this->mX<<endl;
//    cout<<"CSlime.mHP: "<<this->mHP<<endl;
//    cout<<"CSlime.mAP: "<<this->mAP<<endl;
    
    //step_2
    cout<<"CSlime.mX: "<<this->mX<<endl;
    cout<<"CSlime.mHP: "<<this->mHP<<endl;
    cout<<"CSlime.mAP: "<<this->mAP<<endl;
    
    cout<<"CSlime.mStrength: "<<this->mStrength<<endl;
}

//step_1
void CSlime::BuildInfo( int tX, int tHP, int tAP )
{
//    mX = tX;
//    mHP = tHP;
//    mAP = tAP;
    
    
    //step_2
    //이러한 개념을 사용하는 예를 하나 들자면
    //이제 해당 기능을 이루는 코드가 수정되어도 클래스 내부만 수정하면 된다
    //( 외부의 코드는 바꾸지 않아도 된다 )
    mX = tX;
    mHP = tHP;
    mAP = tAP;
    
    mStrength = (mHP - mAP)*3;
}

void CBrave::SetX(int tX)
{
    mX = tX;

}

int CBrave::GetX(int tX)
{

    return tX;
}
//
////step_3
//int CBrave::GetX() const
//{
//    return mX;
//}
//void CBrave::SetX( int tX )
//{
//    mX = tX;
//}
