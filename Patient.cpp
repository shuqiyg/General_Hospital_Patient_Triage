/* Citation and Sources
Final Project Milestone 3
Module: Patient
Filename: Patient.cpp
Version 1.0
Author: Shuqi Yang
Revision History
-----------------------------------------------------------
Date        Reason
2020/03/25  Preliminary release
2020/03/25  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Patient.h"
using namespace std;
namespace sdds {
	Patient::Patient(int tknum, bool io):ticket(tknum) {
		IO = io;	
	}
	Patient::~Patient() {
		delete[] pname;
	}
	bool Patient::fileIO() const {
		return IO;
	}
	void Patient::fileIO(bool io) {
		IO = io;
	}
	bool Patient::operator==(char ch) const {
		return ch == type();
	}
	bool Patient::operator==(const Patient& pt) const {
		return type() == pt.type();
	}
	void Patient::setArrivalTime() {
		ticket.resetTime();
	}
	 Patient::operator Time() const {
		return Time(ticket);
	}
	int Patient::number() const {
		return ticket.number();
	}
	std::ostream& Patient::csvWrite(std::ostream& ostr)const {
		ostr << type() << ',' << pname << ',' << ohip << ',';
		ticket.csvWrite(ostr);
		return ostr;
	}
	std::istream& Patient::csvRead(std::istream& istr) {	
		delete[] pname;
		pname = getcstr("",istr, ',');
		istr >> ohip;
		istr.ignore(1000,',');
		ticket.csvRead(istr);
		return istr;
	}
	std::ostream& Patient::write(std::ostream& ostr)const {
		ostr << ticket << endl;	
		if (pname != nullptr) {
			if (strlen(pname) > 25) {
				for (int i = 0; i < 25; i++) {
					ostr << pname[i];
				}
			}
			else {
				ostr << pname;
			}
		}
		ostr << ", OHIP: " << ohip;
		return ostr;
	}
	std::istream& Patient::read(std::istream& istr) {
		delete[] pname;
		pname = getcstr("Name: ", istr, '\n');
		ohip = getInt(100000000, 999999999,"OHIP: ", "Invalid OHIP Number, ", true);
		return istr;
	}
}