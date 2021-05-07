/* Citation and Sources
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
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
#include <iostream>
#include "TriagePatient.h"

using namespace std;
namespace sdds {
   int nextTriageTicket = 1;
   TriagePatient::TriagePatient():Patient(nextTriageTicket) {
	   symptoms = nullptr;
	   nextTriageTicket++;
   }
	char TriagePatient::type()const {
		return 'T';
   }
   std::ostream& TriagePatient::csvWrite(std::ostream& ostr)const {
	  return  Patient::csvWrite(ostr) << ',' << symptoms;

   }
    std::istream& TriagePatient::csvRead(std::istream& istr) {
		delete[] symptoms;
		Patient::csvRead(istr);
		istr.ignore(1000, ',');
		symptoms = getcstr("", istr, '\n');
		nextTriageTicket = number() + 1;
		return istr;
   }			  
	std::ostream& TriagePatient::write(std::ostream& ostr) const {
		if (fileIO()) {
			csvWrite(ostr);
		}
		else {
			ostr << "TRIAGE" << endl;
			Patient::write(ostr) << endl << "Symptoms: " << symptoms << endl;		
		}
		return ostr;
   }			  
	std::istream& TriagePatient::read(std::istream& istr) {
		if (fileIO()) {
			csvRead(istr);
		}
		else {
			delete[] symptoms;
			Patient::read(istr);
			symptoms = getcstr("Symptoms: ", istr, '\n');
		}
		return istr;
   }
   TriagePatient::~TriagePatient() {
	   delete[] symptoms;
   }
}