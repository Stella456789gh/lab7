#pragma once
#include <iostream>
#include <cstdlib>
// 2. dayOfYear.h : 클래스1 정의
namespace KwonMinSung2693018
{
//[lab7] 
//달별로 날의 수를 정수형 배열로 정의
    const int daysInMonth[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};

class dayOfYear
{
// 1의 본인이름학번의 네임스페이스 안에 클래스1을 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언 (2개 이상)
// private 멤버함수 정의
// -test멤버변수1: 멤버변수1 범위가 아니면 프로그램 종료
// -test멤버변수2: 멤버변수2 범위가 아니면 프로그램 종료
private:
    int month{};
    int day{};
    void testMonth()
    {
        if ((month < 1) || (month > 12)) 
        {
            std::cout << "Invalid Month\n";
            std::exit(1);
        }
    }
    void testDay()
    {
        if ((day < 1) || (day > daysInMonth[month])) 
        {
            std::cout << "Invalid Day\n";
            std::exit(1);
        }
    }
    void updateDay()
    {
        int maxDay{daysInMonth[month]};

        while (day > maxDay)
        {
            day = day - maxDay;
            month = month + 1;
            if(month > 12) month = month - 12;
            maxDay = daysInMonth[month];
        }
    }

// public 멤버함수 정의
// -생성자: 모든 멤버변수 초기화, 기본값 설정, test함수들 호출
// -input: 표준스트림입력으로 멤버변수들 입력, test함수들 호출
// -set 접근함수들: 멤버변수 값 설정 및 test함수 호출
// -print: 표준스트림출력으로 멤버변수들 출력
// -get 접근함수들: 멤버변수 값 리턴
public:
    dayOfYear (int m=1, int d=1) : month{m}, day{d}
    {
        testMonth(); testDay();
    }
    void input()
    {
        std::cout << "Enter Month: ";
        std::cin >> month;
        testMonth();
        std::cout << "Enter Day: ";
        std::cin >> day;
        testDay();
    }
    void setMonth(int m) {month = m; testMonth();} // 날짜 바꾸고 싶어질떄 세팅
    void setDay(int d) {day = d; testDay();}
    void print() const
    {
        switch(month)
        {
            case 1 : std::cout << "Jan. "; break;
            case 2: std::cout << "Feb. "; break;
            case 3: std::cout << "Mar. "; break;
            case 4: std::cout << "Apr. "; break;
            case 5: std::cout << "May. "; break;
            case 6: std::cout << "Jun. "; break;
            case 7: std::cout << "Jul. "; break;
            case 8: std::cout << "Aug. "; break;
            case 9: std::cout << "Sep. "; break;
            case 10: std::cout << "Oct. "; break;
            case 11: std::cout << "Nov. "; break;
            case 12: std::cout << "Dec. "; break;
        }
        std::cout << day << "\n";
    }
    int getMonth() const {return month;}
    int getDay() const {return day;}

 // -프렌드함수로서 입력연산자 >>
    friend std::istream& operator>> (std::istream& is, dayOfYear& d)
    {
        std::cout << "Enter Month: ";
        is >> d.month;//클래스 바깥에 있는 전역함수이므로 객체지정해야함
        d.testMonth();
        std::cout << "Enter Day: ";
        is >> d.day;
        d.testDay();

        return is;
    }
 // -프렌드함수로서 출력연산자 <<
    friend std::ostream& operator << (std::ostream& os, const dayOfYear& d)
    {
        switch(d.month)
        {
            case 1: os << "Jan. "; break;
            case 2: os << "Feb. "; break;
            case 3: os << "Mar. "; break;
            case 4: os << "Apr. "; break;
            case 5: os << "May. "; break;
            case 6: os << "Jun. "; break;
            case 7: os << "Jul. "; break;
            case 8: os << "Aug. "; break;
            case 9: os << "Sep. "; break;
            case 10: os << "Oct. "; break;
            case 11: os << "Nov. "; break;
            case 12: os << "Dec. "; break;
        } 
        os << d.day << "\n";

        return os;
    }

// [lab7]
// -멤버함수로 전위증가연산자 정의, -멤버함수로 후위증가연산자 정의

// -전위증가연산자의 리턴을 참조리턴으로 변경
// -전위증가연산자, 후위증가연산자를 this를 이용하게 변경
// -복합할당연산자 += 정의 (this 이용)

    dayOfYear& operator ++()
    {
        ++day;
        updateDay();
        return *this; //dayOfYear{month,day};
        //자기자신 객체가 가르키는 (화살표의 도착지) 값 자체 원본을 그대로 반환
    }
      

    dayOfYear operator ++(int)
    {
        dayOfYear temp {*this} //{month,day};
        ++day;
        updateDay(); // ++(*this);
        return temp;
    }



 //프렌드함수로서 이항연산자 ==
    friend bool operator == (const dayOfYear& d1, const dayOfYear& d2)
    {
        return d1.month == d2.month && d1.day == d2.day;
    }
 //프렌드함수로서 이항연산자 + 정의
    friend dayOfYear operator +(const dayOfYear& d1, const dayOfYear& d2)
    {
        return dayOfYear{d1.month + d2.month, d1.day + d2.day};
    }


};

}