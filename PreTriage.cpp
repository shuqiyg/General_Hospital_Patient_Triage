/* Citation and Sources
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author: Shuqi Yang
Revision History
-----------------------------------------------------------
Date        Reason
2020/03/31  Preliminary release
2020/03/31  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
using namespace std;
namespace sdds {
    void PreTriage::reg() {
        if (m_lineupSize == maxNoOfPatients) {
            cout << "Line up full!" << endl;
            return;
        }
        int selection;
        m_pMenu >> selection;
        switch (selection) {
        case 1:
            m_lineup[m_lineupSize] = new CovidPatient();
            break;
        case 2:
            m_lineup[m_lineupSize] = new TriagePatient();
            break;
        case 0:
            return;
        }
        m_lineup[m_lineupSize]->setArrivalTime();
        cout << "Please enter patient information: " << endl;
        m_lineup[m_lineupSize]->fileIO(false);
        cin >> *m_lineup[m_lineupSize];
        cout << endl << "******************************************" << endl;
        cout << *m_lineup[m_lineupSize];
        cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
        cout << "******************************************" << endl << endl;
        m_lineupSize++;     
    }
    void PreTriage::admit(){
        int selection, index;
        char type;
        m_pMenu >> selection;
        switch (selection) {
        case 1:
            type = 'C';
            break;
        case 2:
            type = 'T';
            break;
        case 0:
            return;
        }
        index = indexOfFirstInLine(type);
        if (index == -1) return;
        cout << endl << "******************************************" << endl;
        m_lineup[index]->fileIO(false);
        cout << "Calling for " << *m_lineup[index] << "******************************************" << endl << endl;
        setAverageWaitTime(*m_lineup[index]);
        removePatientFromLineup(index);
    }  
    const Time PreTriage::getWaitTime(const Patient& p)const {
        Time waitTime(0);
        for (int i= 0; i < m_lineupSize; i++) {
            if (p.type() == m_lineup[i]->type()) {
                waitTime += Time(*m_lineup[i]) ;
            }
        }
        return waitTime;
    }
    void PreTriage::setAverageWaitTime(const Patient& p) {
        Time CT;
        CT.setToNow();
        if (p.type() == 'C') {
            m_averCovidWait = ((CT - Time(p)) + (m_averCovidWait * (unsigned int)((p.number() - 1)))) / (unsigned int) (p.number());
        }
        else if (p.type() == 'T') {
            m_averTriageWait = ((CT - Time(p)) + (m_averTriageWait * (unsigned int)((p.number() - 1)))) / (unsigned int)(p.number());
        }
    }
    void PreTriage::removePatientFromLineup(int index) {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }
    int PreTriage::indexOfFirstInLine(char type) const {
        for (int i = 0; i < m_lineupSize; i++) {
            if (type == m_lineup[i]->type()) {
                return i;
            }
        }
        return -1;
    }
    void PreTriage::load() {
        ifstream fin(m_dataFilename);
        cout << "Loading data...\n";
        fin >> m_averCovidWait;
        fin.ignore();
        fin >> m_averTriageWait;
        fin.ignore();
        Patient* temp = nullptr;
        char type;
        for (int i = 0; i < maxNoOfPatients && fin; i++) {
            fin >> type;
            fin.ignore();
            if (fin) {          
                if (type == 'C') {
                    temp = new CovidPatient();
                }
                else if (type == 'T') {
                    temp = new TriagePatient();
                }
                if (temp != nullptr) {
                    temp->fileIO(true);
                    fin >> *temp;
                    temp->fileIO(false);
                    m_lineup[i] = temp;
                    m_lineupSize++;
                }    
            }
        }
        if (!fin.eof()) {
            cout << "Warning: number of records exceeded 100\n100 Records imported..." << endl;
        }
        else if(m_lineupSize == 0){
            cout << "No data or bad data file!" << endl;
        }
        else {
            cout << m_lineupSize << " Records imported..." << endl;
        }
        cout << endl;
    }
    PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2){
        delete[] m_dataFilename;
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename, dataFilename);        
        load();
    }
    PreTriage::~PreTriage() {
        ofstream fout(m_dataFilename);
        cout << "Saving Average Wait Times," << endl << "   COVID Test: " << m_averCovidWait << endl << "   Triage: " << m_averTriageWait <<endl;
        fout << m_averCovidWait << ',' << m_averTriageWait << '\n';
        cout << "Saving m_lineup..." << endl;
        for (int i = 0; i < m_lineupSize; i++) {
            m_lineup[i]->fileIO(true);
            cout << i + 1 << "- " << *m_lineup[i] << endl;
            fout << *m_lineup[i];
            fout << endl;
        }
        fout.close();
        for (int i = 0; i < m_lineupSize; i++) {
            delete m_lineup[i];
            m_lineup[i] = nullptr;
        }   
        delete[] m_dataFilename;
        cout << "done!" << endl;
    }
    void PreTriage::run(void) {   
        int selection, repeat = 1;
        while (repeat) {
            m_appMenu >> selection;
            switch (selection) {
            case 0:
                repeat = -1;
                return;
            case 1:
                reg();
                break;
            case 2:
                admit();
                break;
                }
            }    
        }   
}