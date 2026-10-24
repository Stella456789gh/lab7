#include <iostream>
#include "dayOfYear.h"

// 3. main.cpp: 테스트
// 1의 본인이름학번의 네임스페이스안에 
// parVal, parRef, parPtr 함수를 정의: 각각 클래스1 형의 값, 참조, 포인터를 매개변수로 갖고, 
// 매개변수+1하고 리턴은 없음 (복합할당연산자+= 사용)

// retVal, retRef, retPtr 함수를 정의: 각각 클래스1 형의 값, 참조, 포인터를 매개변수로 갖고, 
// 매개변수+1해준 (복합할당연산자+= 사용) 후 값, 참조, 포인터를 리턴함
namespace KwonMinSung2693018
{
    void parVal(dayOfYear d) {d+=1;}
    void parRef(dayOfYear& r) {r+=1;}
    void parPtr(dayOfYear* p) {*p+=1;}
    
    dayOfYear retVal(dayOfYear d) {d+=1; return d;}
    dayOfYear& retRef(dayOfYear& r) {r+=1; return r;}
    dayOfYear* retPtr(dayOfYear* p) {*p+=1; return p;}
}
// -main 
int main()
{
using namespace KwonMinSung2693018;
// 클래스1 객체 선언, 원하는 값으로 초기화, 출력연산자를 이용하여 선언한 객체를 표준스트림으로 출력
// parVal함수에 선언한 객체를 인자로 넣은 후, 출력연산자를 이용하여 선언한 객체를 표준스트림으로 출력
// 선언한 객체를 참조하는 참조객체를 선언하고, 출력연산자를 이용하여 참조객체를 표준스트림으로 출력
// parRef함수에 참조객체를 인자로 넣은 후, 출력연산자를 이용하여 참조객체를 표준스트림으로 출력
// 선언한 객체를 가리키는 포인터변수를 선언, 출력연산자를 이용하여 포인터변수가 가리키는 값을 표준스트림으로 출력
// parPtr함수에 포인터변수를 인자로 넣은 후, 출력연산자를 이용하여 포인터변수가 가리키는 값을 표준스트림으로 출력
    dayOfYear d{10,25}; std::cout << d;     //10,25
    parVal(d); std::cout << d;              //10,25
    dayOfYear& r{d}; std::cout << r;        //10,25
    parRef(r); std::cout << r;              //10,26
    dayOfYear* p{&d}; std::cout << *p;      //10,26
    parPtr(p); std::cout << *p;             //10,27


// 선언한 객체에 생성자를 명시적으로 호출하게 원하는 값을 넣기
// 출력연산자를 이용하여 선언한 객체를 표준스트림으로 출력
// retVal함수에 선언한 객체를 인자로 넣어 리턴값을 표준스트림으로 출력
// 출력연산자를 이용하여 참조객체를 표준스트림으로 출력
// retRef함수에 참조객체을 인자로 넣어 리턴값을 표준스트림으로 출력
// 출력연산자를 이용하여 포인터변수가 가리키는 값을 표준스트림으로 출력
// retPtr함수에 포인터변수를 인자로 넣어 리턴값이 가리키는 값을 표준스트림으로 출력
    d = dayOfYear{11,2};
    std::cout << d;             //11,2
    std::cout << retVal(d);     //11,3
    std::cout << r;             //11,2
    std::cout << retRef(r);     //11,3
    std::cout << *p;            //11,3
    std::cout << *retPtr(p);    //11,4

// 클래스1 형을 가리키는 포인터변수를 선언하고, 동적할당 (동적변수)  
// set함수를 이용하여 원하는 값을 넣어준 후 동적변수가 가리키는 값을 출력연산자를 이용하여 표준스트림으로 출력
// 동적할당한 메모리 해제
    dayOfYear *ptr{ new dayOfYear };
    ptr->setMonth(10);
    ptr->setDay(11);
    std::cout << *ptr;

    delete ptr;

    return 0;
}