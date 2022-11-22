//
//  main.cpp
//  cpp_oop_abstract_1
//
//  Created by pokpoongryu on 2020/03/03.
//  Copyright © 2020 pokpoongryu. All rights reserved.
//

/*
    created by pokpoongryu
 
    OOP의 4가지 특징
 
    추상화 abstraction
 
        추상화에 class 를 이용해보자.
 
        데이터의 추상화 + 코드의 추상화 ==> 사용자 정의 타입( 데이터 )
 
 */



#include <iostream>

using namespace std;


//step_0
class CSlime
{
    int mX     = 0;
    int mHP    = 100;
    int mAP    = 30;

    void DisplayInfo();
};


//step_1
class CSlimeBoss
{
    //public 예약어는 멤버 들을 '어디서나 접근 가능'하게 만들어준다.
    /*
        접근 제어 연산자
            
            private: 해당 클래스에서만 접근 가능
            protected: 상속계통구조 에서만 접근 가능
            public: 어디서나 접근가능
    */
    
public:
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
    CSlime tSlime;
    
    //해당 클래스의 선언정의시 아무 표기가 없으면
    //외부에서는 멤버에 접근할 수 없다.
    //왜냐하면, class의 '접근제어 연산' 지정이 private 가 기본이기 때문이다.
//    cout<<"tSlime.mX: "<<tSlime.mX<<endl;
//    cout<<"tSlime.mHP: "<<tSlime.mHP<<endl;
//    cout<<"tSlime.mAP: "<<tSlime.mAP<<endl;
//
//    tSlime.DisplayInfo();
    
    
    cout<<endl;
    
    //step_1
    CSlimeBoss tSlimeBoss;
    tSlimeBoss.mX = 3;
    tSlimeBoss.mHP = 1004;
    tSlimeBoss.mAP = 987;
    
    tSlimeBoss.DisplayInfo();
    
    
    return 0;
}


void CSlime::DisplayInfo()
{
    cout<<"CSlime.mX: "<<this->mX<<endl;
    cout<<"CSlime.mHP: "<<this->mHP<<endl;
    cout<<"CSlime.mAP: "<<this->mAP<<endl;
}

//step_1
void CSlimeBoss::DisplayInfo()
{
    cout<<"CSlimeBoss.mX: "<<this->mX<<endl;
    cout<<"CSlimeBoss.mHP: "<<this->mHP<<endl;
    cout<<"CSlimeBoss.mAP: "<<this->mAP<<endl;
}
