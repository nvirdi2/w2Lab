// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Jan 28, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "File.h"

namespace sdds 
{
   FILE* fptr;


   bool openFile(const char filename[]) 
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }


   int noOfRecords() 
   {
      int noOfRecs = 0;
      char ch;

      while (fscanf(fptr, "%c", &ch) == 1)
      {
         noOfRecs += (ch == '\n');
      }

      rewind(fptr);
      return noOfRecs;
    }


   void closeFile() 
   {
      if (fptr) 
            fclose(fptr);
   }


   //TODO: read functions go here    
   bool read(int& employeeNumber) 
   {
      if (fscanf(fptr, "%d,", &employeeNumber) != 0) 
      {
         return 1;
      } return 0;
   }


   bool read(char* employeeName) 
   {
      if (fscanf(fptr, "%[^\n]\n", employeeName) != 0) 
      {
         return 1;
      } return 0;
   }


   bool read(double& employeeSalary) 
   {
      if (fscanf(fptr, "%lf,", &employeeSalary) != 0) 
      {
         return 1;
      } return 0;
   }
}
