/* Citation and Sources
Final Project Milestone 2
Module: IOAble interface 
Filename: IOAble.h
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
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>

namespace sdds{
	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream&)const = 0;
		virtual std::istream& csvRead(std::istream&) = 0;
		virtual std::ostream& write(std::ostream&)const = 0;
		virtual std::istream& read(std::istream&) = 0;
		virtual ~IOAble();
	};
	std::ostream& operator<<(std::ostream&, const IOAble&);
	std::istream& operator>>(std::istream&, IOAble&);
}
#endif