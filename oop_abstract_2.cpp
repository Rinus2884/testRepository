//
//  main.cpp
//  cpp_oop_abstract_2_constructor
//
//  Created by pokpoongryu on 2020/03/03.
//  Copyright © 2020 pokpoongryu. All rights reserved.
//

/*
    created by pokpoongryu
 
    OOP의 4가지 특징
 
    추상화 abstraction
 
        class 로 '객체' 를 만든다.
        ( '타입으로 변수를 만든다' 와 기본적인 형식은 같다.
            하지만, 이제 보다 고차원적으로 추상적으로 생각하고 다루는 것이다. )
        
        객체는 '생성자'와 '소멸자'를 갖는다.
        생성자와 소멸자는 클래스의 이름을 따른다.
 
 
    디버거로 생성자와 소멸자의 실행흐름을 짚어보자.
 
 */



#include <iostream>

using namespace std;


//step_0
class CSlime
{
public:
    
    int mX     = 0;
    int mHP    = 100;
    int mAP    = 30;

    void DisplayInfo();
    
    //생성자와 소멸자는 리턴 타입이 표기되지 않는다.
    //만들지 않으면, 컴파일러가 기본적인 생성자와 소멸자는 암묵적으로 만든다.
    CSlime();
    ~CSlime();
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "cpp_oop_abstract_0\n";
    
    //step_0
    CSlime tSlime;
    
    tSlime.DisplayInfo();
    
    
    cout<<endl;
    
    
    
    
    //step_1
    CSlime *tpSlime = nullptr;
    tpSlime = new CSlime();
    
    if( nullptr != tpSlime )
    {
        tpSlime->mX = 5;
        tpSlime->mHP = 5000;
        tpSlime->mAP = 777;
        
        tpSlime->DisplayInfo();
    }
    
    
    if( nullptr != tpSlime )
    {
        delete tpSlime;
        tpSlime = nullptr;
    }
    
    
    return 0;
}


CSlime::CSlime()
{
    //객체가 생성되는 시점에 자동으로 호출된다.
    //변수의 초기화 작업 등을 할 수 있다.
    mX     = 0;
    mHP    = 100;
    mAP    = 30;
    
    cout<<"CSlime::CSlime()"<<endl;
}

CSlime::~CSlime()
{
    //객체가 소멸되는 시점에 자동으로 호출된다.
    cout<<"CSlime::~CSlime()"<<endl;
}


void CSlime::DisplayInfo()
{
    cout<<"CSlime.mX: "<<this->mX<<endl;
    cout<<"CSlime.mHP: "<<this->mHP<<endl;
    cout<<"CSlime.mAP: "<<this->mAP<<endl;
}
