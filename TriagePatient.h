/* Citation and Sources
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
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
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include "Patient.h"

namespace sdds {
	class TriagePatient : public Patient {
		char* symptoms;
	public:
		TriagePatient();
		virtual char type()const;
		virtual std::ostream& csvWrite(std::ostream&)const;
		virtual std::istream& csvRead(std::istream&);
		virtual std::ostream& write(std::ostream&) const;
		virtual std::istream& read(std::istream&);
		~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


