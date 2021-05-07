/* Citation and Sources
Final Project Milestone 2
Module: Utils
Filename: utils.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include <climits>
#include "Time.h"

using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getInt(const char* prompt) {
       int intInput;
       char NL;
       if (prompt != nullptr) {
           cout << prompt;
       }
       do {  
           while (!(cin >> intInput)) {
               cin.clear();
               cin.ignore(INT_MAX, '\n');
               cout << "Bad integer value, try again: ";
           }
           cin.get(NL);
           if (NL != '\n') {
               cin.clear();
               cin.ignore(INT_MAX, '\n');
               cout << "Enter only an integer, try again: ";
           }
       } while (NL != '\n');
       return intInput;
   }
   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
       int intInput;
       if (prompt != nullptr) {
           cout << prompt;
       }
       do {
           intInput = getInt();
           if (intInput < min || intInput > max) {
               if (errorMessage != nullptr) {
                   cout << errorMessage;
               }
               if (showRangeAtError) {
                   cout << "[" << min << " <= value <= " << max << "]: ";
               }
           }
       } while (intInput < min || intInput > max);
       return intInput;
   }
   char* getcstr(const char* prompt , std::istream& istr , char delimiter) {
       /* Cstring implementaiton -------
       char* str = nullptr;
       char* temp = new char[1000];
       if (prompt != nullptr) {
           cout << prompt;
           int charCount = 0;
           char charInput;
           while (cin.get(charInput) && charInput != delimiter) {
               charCount++;
               temp[charCount-1] = charInput;
           }
           temp[charCount] = '\0';
           cin.clear();
           //cin.get();
           //cin.ignore(INT_MAX, '\n');
           str = new char[charCount + 1];
           strcpy(str, temp);
           delete[] temp;
       } 
       --------------------------*/
       string str;
       if (prompt != nullptr) {
           cout << prompt;
       }
       getline(istr, str, delimiter);
       char* cstr = new char[str.length() + 1];
       strcpy(cstr, str.c_str());    
       return cstr;
   }
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
}