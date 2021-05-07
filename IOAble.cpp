/* Citation and Sources
Final Project Milestone 2
Module: IOAble interface
Filename: IOAble.cpp
Version 1.0
Author: Shuqi Yang
Revision History
-----------------------------------------------------------
Date        Reason
2020/03/20  Preliminary release
2020/03/20  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "IOAble.h"
namespace sdds {
	IOAble::~IOAble() {}
	std::ostream& operator<<(std::ostream& ostr, const IOAble& io) {
		return io.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, IOAble& io) {
		return io.read(istr);
	}
}