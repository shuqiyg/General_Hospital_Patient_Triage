/* Citation and Sources
Final Project Milestone 2
Module: Utils
Filename: utils.h
Version 1.0
Author: Shuqi Yang
Revision History
-----------------------------------------------------------
Date        Reason
2020/03/15  Preliminary release
2020/03/15  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------

*/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   extern bool debug; // making sdds::debug variable global to all the files
                      // which include: "utils.h"
   template <typename type>
   void removeDynamicElement(type* array[], int index, int& size) {
       delete array[index];
       for (int j = index; j < size; j++) {
           array[j] = array[j + 1];
       }
       size--;
   };
   int getInt(const char* prompt = nullptr);
   int getInt(int, int, const char* prompt = nullptr, const char* errorMessage = nullptr, bool showRangeAtError = true);
   char* getcstr(const char* prompt = nullptr, std::istream& istr = std::cin, char delimiter = '\n');
   int getTime(); // returns the time of day in minutes
   
}
#endif // !SDDS_UTILS_H_

