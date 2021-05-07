/* Citation and Sources
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.h
Version 1.0
Author: Shuqi Yang
Revision History
-----------------------------------------------------------
Date        Reason
2020/03/28  Preliminary release
2020/03/28  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include <iostream>
#include "Patient.h"


namespace sdds {
	//int nextCovidTicket = 0;
	class CovidPatient: public Patient {
	public:
		CovidPatient();
		virtual char type()const;
		virtual std::istream& csvRead(std::istream&);
		virtual std::ostream& write(std::ostream&)const;
		virtual std::istream& read(std::istream&);
	};
}
#endif // !SDDS_COVIDPATIENT_H_



