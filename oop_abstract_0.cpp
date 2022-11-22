//
//  main.cpp
//  cpp_oop_abstract_0
//
//  Created by pokpoongryu on 2020/03/03.
//  Copyright © 2020 pokpoongryu. All rights reserved.
//

/*
    created by pokpoongryu
 
    OOP의 4가지 특징
 
    추상화 abstraction
 
        struct를 이용한 데이터의 추상화와 함수를 이용한 코드의 추상화를 묶어보자.
 
 
 */



#include <iostream>

using namespace std;


//step_0
//cpp 스타일로 '구조체'의 선언정의는 이렇게 간단히 할 수 있다.( typedef을 안씀 )
//cpp 스타일로 선언정의시 바로 멤버변수 초기화도 가능하다.
struct SSlime
{
//    int mSlimeX     = 0;
//    int mSlimeHP    = 100;
//    int mSlimeAP    = 30;
    int mX     = 0;
    int mHP    = 100;
    int mAP    = 30;
};


//step_1
void DisplaySlimeInfo( SSlime &tSlime );



//step_2
//데이터의 추상화와 코드의 추상화를 묶자.
struct SSlimeBoss
{
    //멤버변수
    int mX     = 0;
    int mHP    = 100;
    int mAP    = 30;
    
    //멤버함수
    void DisplayInfo();
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "cpp_oop_abstract_0\n";
    
    //step_0
//    int mSlimeX     = 0;
//    int mSlimeHP    = 100;
//    int mSlimeAP    = 30;
    
    SSlime tSlime;
    
    cout<<"tSlime.mX: "<<tSlime.mX<<endl;
    cout<<"tSlime.mHP: "<<tSlime.mHP<<endl;
    cout<<"tSlime.mAP: "<<tSlime.mAP<<endl;
    
    
    cout<<endl;
    
    //step_1
    SSlime tSlime_A;
    tSlime_A.mX = 1;
    tSlime_A.mHP = 133;
    tSlime_A.mAP = 77;
    
    DisplaySlimeInfo( tSlime_A );
    
    
    //step_2
    SSlimeBoss tSlimeBoss;
    tSlimeBoss.mX = 4;
    tSlimeBoss.mHP = 1004;
    tSlimeBoss.mAP = 256;
    
    tSlimeBoss.DisplayInfo();
    
    
    
    
    return 0;
}


//step_1
void DisplaySlimeInfo( SSlime &tSlime )
{
    cout<<"tSlime.mX: "<<tSlime.mX<<endl;
    cout<<"tSlime.mHP: "<<tSlime.mHP<<endl;
    cout<<"tSlime.mAP: "<<tSlime.mAP<<endl;
}


//step_2
void SSlimeBoss::DisplayInfo()
{
    //this 는 객체 자기자신을 가리키는 포인터 변수이다.
//    cout<<"tSlimeBoss.mX: "<<(*this).mX<<endl;
//    cout<<"tSlimeBoss.mHP: "<<(*this).mHP<<endl;
//    cout<<"tSlimeBoss.mAP: "<<(*this).mAP<<endl;
    
    //(*. ). 은 -> 연산자로 표기를 바꾸어 쓸 수도 있다.
//    cout<<"tSlimeBoss.mX: "<<this->mX<<endl;
//    cout<<"tSlimeBoss.mHP: "<<this->mHP<<endl;
//    cout<<"tSlimeBoss.mAP: "<<this->mAP<<endl;
    
    
    //해당 표현은 표기를 생략할 수도 있다.
    cout<<"tSlimeBoss.mX: "<<mX<<endl;
    cout<<"tSlimeBoss.mHP: "<<mHP<<endl;
    cout<<"tSlimeBoss.mAP: "<<mAP<<endl;
}
