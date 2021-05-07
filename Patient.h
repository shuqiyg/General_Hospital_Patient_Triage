/* Citation and Sources
Final Project Milestone 3
Module: Patient
Filename: Patient.h
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
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include <iostream>
#include <string>
#include <cstring>
#include "IOAble.h"
#include "Ticket.h"
#include "utils.h"

namespace sdds {
	class Patient : public IOAble {
		char* pname = nullptr;
		int ohip = 0;
		bool IO;
		Ticket ticket;
	public:
		Patient(int tknum = 0, bool io = false);
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		~Patient();
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool);
		bool operator==(char) const;
		bool operator==(const Patient&) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		virtual std::ostream& csvWrite(std::ostream&)const;
		virtual std::istream& csvRead(std::istream&);
		virtual std::ostream& write(std::ostream&)const;
		virtual std::istream& read(std::istream&);
	};
}
#endif