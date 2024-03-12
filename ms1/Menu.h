/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author   John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2024/3/10 Start attempt 1
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;

namespace seneca {
	class Menu {
		char* m_text{};
		int m_noOfOpt{};
		int m_noOfTab{};
		void printIndent();
		int getSelection();
	public:
		Menu(const char* menuContent, int numberOfTabs = 0);
		Menu(const Menu& menu) = delete;
		~Menu();
		
		Menu& operator=(const Menu& menu) = delete;
		ostream& display();
		int& operator>>(int& Selection);
	};
}

#endif // !MENU_H
