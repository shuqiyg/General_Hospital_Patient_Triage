/* Citation and Sources
Final Project Milestone 2
Module: Time
Filename: Time.cpp
Version 1.0
Author: Shuqi Yang
Revision History
-----------------------------------------------------------
Date        Reason
2020/03/15  Preliminary release
2020/03/15  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------

*/
#include "Time.h"
#include "utils.h"
#include <iostream>

using namespace std;
namespace sdds {
    Time& Time::setToNow() {
        m_min = getTime();
        return *this;
    }
    Time::Time(unsigned int min) {
        m_min = min;
    }
    std::ostream& Time::write(std::ostream& ostr) const {
        int mins;
        int hours;
        hours = m_min / 60;
        mins = m_min % 60;
        ostr.width(2);
        ostr.fill('0');
        ostr << hours << ":";
        ostr.width(2);
        ostr << mins;
        ostr.fill(' ');
        return ostr;
    }
    std::istream& Time::read(std::istream& istr) {
        int hours;
        int mins;
        char colon;
        if (!(istr >> hours) || hours < 0) {
            istr.setstate(ios::failbit);
        }
        if (!(istr >> colon) || colon != ':') {
            istr.setstate(ios::failbit);
        }
        if (!(istr >> mins) || mins < 0) {
            istr.setstate(ios::failbit);
        }
        if (!istr.fail()) {
            m_min = hours * 60 + mins;
        }
        return istr;
    }
    Time& Time::operator-=(const Time& D) {
        if (m_min >= D.m_min) {
            m_min -= D.m_min;
       }
        else {
             m_min = m_min + ((D.m_min / 60 / 24 + 1) * 24 * 60 - D.m_min);            
        }
        return *this;
    }
    Time Time::operator-(const Time& D)const {
        Time temp = m_min;
        temp -= D;
        return temp;
    }
    Time& Time::operator+=(const Time& D) {
        m_min += D.m_min;
        return *this;
    }
    Time Time::operator+(const Time& D)const {
        Time temp = m_min;
        temp += D;
        return temp;
    }
    Time& Time::operator=(unsigned int val) {
        m_min = val;
        return *this;
    }
    Time& Time::operator *= (unsigned int val) {
        m_min *= val;
        return *this;
    }
    Time& Time::operator /= (unsigned int val) {
        m_min /= val;
        return *this;
    }
    Time Time::operator *(unsigned int val)const {
        Time temp = m_min;
        temp.m_min *= val;
        return temp;
    }
    Time Time::operator /(unsigned int val)const {
        Time temp = m_min;
        temp /= val;
        return temp;
    }
    Time::operator unsigned int()const {
        return m_min;
    }
    Time::operator int()const {
        return int(m_min);
    }
    std::ostream& operator<<(std::ostream& ostr, const Time& D) {   
        return D.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Time& D) {
        return D.read(istr);
    }
}