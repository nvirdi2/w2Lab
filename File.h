// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Jan 28, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <cstdio>
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds 
{
   //supplied by professor
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   // TODO: Declare read prototypes
   bool read (double& employeeSalary);
   bool read (int& employeeNumber);
   bool read (char* employeeName);
}
#endif // !SDDS_FILE_H_
