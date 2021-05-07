/* Citation and Sources
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
#include "utils.h"

namespace sdds {
	class Menu {
		char* m_text{ nullptr };  //holds the menu content dynamically
		int m_noOfSel;  // holds the number of options displayed in menu content
		void display()const;
	public:
		//Menu();
		Menu(const char* MenuContent, int NoOfSelections);
		virtual ~Menu();
		int& operator >> (int& Selection);
		//add safe copying logic
		Menu(const Menu&);
		Menu& operator=(const Menu&) = delete;
		};
}
#endif

