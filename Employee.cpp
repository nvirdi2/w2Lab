// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Jan 28, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>

#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"

using namespace std;
namespace sdds 
{

    int noOfEmployees;
    Employee* employees;


//sort fuction - given by professor
    void sort() 
    {
        int i = 0, j = 0;
        Employee temp = {};
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }


// TODO: Finish the implementation of the 0 arg load function 
    bool load() 
    {
        bool ok = false;
        int x = 0;

        if (openFile(DATAFILE)) 
        {
            /* 
          Set the noOfEmployees to the number of recoreds in the file.
          dyanamically allocated an array of employees into the global
          Employee pointer; "employees" to the size of the noOfEmployees.
          In a loop load the employee records from the file into 
          the dynamic array.
          If the number of the records does not match the number of reads
             print the message
            "Error: incorrect number of records read; the data is possibly corrupted"
          Otherwise
             set the ok flag to true
          End if
          close the file
          */

            noOfEmployees = noOfRecords() + 1;
            employees = new Employee[noOfEmployees]{};

            for (x = 0; x < noOfEmployees; x++) 
            {

                if (!load(employees[x])) 
                {

                    cout << "Error: incorrect number of records read; the data is possibly corrupted"<< endl;
                    
                    closeFile();
                    return false;
                }
            }

            ok = true;
            closeFile();
        }

        else 
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        } return ok;
    }


// TODO: Implementation for the display functions go here
// reads one employee record from the file and loads it into the employee reference
// argument
    bool load(Employee& Employee) 
    {
        bool ok = false;
        char name[128] = {'\0'};

        /* if reading of employee number, salay and name are successful
              allocate memory to the size of the name + 1
              and keep its address in the name of the Employee Reference
              copy the name into the newly allocated memroy
              make sure the "ok" flag is set to true
         end if
      */

            if (read(Employee.m_empNo)) 
            {
                if (read(Employee.m_salary)) 
                {
                    if (read(name)) 
                    {
                    int x = strLen(name);

                    Employee.m_name = new char [x+1];
                    strCpy(Employee.m_name, name);

                    ok = true;
                }
            }
        } return ok;
    }


// TODO: Implementation for the display functions go here
    void display() 
    {
        sort();

        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        int l = 0;
        int x = 0;

        for (l = 0; l < noOfEmployees; l++)
        {

            if (employees[l].m_name[0] != '\0') 
            {

                cout << l + 1 + x << "- ";
                display(employees[l]);
            }

            else 
            { 
                x--; 
            }
        }
    }
   

    void display(const Employee& employee) 
    {
        cout << employee.m_empNo << ": " << employee.m_name 
                << ", " << employee.m_salary << endl;
    }


// TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() 
    {
        int x = 0;
    
        for (x = 0; x < noOfEmployees; x++) 
        {
            delete[] employees[x].m_name;
        }

        delete[] employees;
        }
    }
