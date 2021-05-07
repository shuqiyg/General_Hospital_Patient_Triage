/* Citation and Sources
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>

using namespace std;
namespace sdds {
	void Menu::display()const {
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}
	Menu::Menu(const char* MenuContent, int NoOfSelections) {
		if (MenuContent != nullptr) {
			m_text = new char[strlen(MenuContent) + 1];
			strcpy(m_text, MenuContent);
		}
		m_noOfSel = NoOfSelections;
	}
	Menu::~Menu() {
		delete[] m_text;
		m_text = nullptr;
	}
	int& Menu::operator>>(int& Selection) {
		display();
		return Selection = getInt(0, m_noOfSel,"> ","Invalid option ",true);
	}
	Menu::Menu(const Menu& m) {
		if (m.m_text != nullptr) {
			m_text = new char[strlen(m.m_text) + 1];
			strcpy(m_text, m.m_text);
		}
		m_noOfSel = m.m_noOfSel;
	}
}