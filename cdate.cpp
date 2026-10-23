#include <stdio.h>
#include <iostream>
#include <ctime>  
#include <malloc.h>
#include <iomanip>

using namespace std;

#include "cdate.h"


void CDate::setDate(int dd, int mm, int yyyy)
{
    if (dd >= 1 && dd <= 31 && (mm + 1) >= 1 && (mm + 1) <= 12 && yyyy >= 1900 && yyyy <= 2099)
    {
        Day = dd;
        Month = mm;
        Year = yyyy;
    }
    else
        Day = Month = Year = 0;
}

// Konstruktor für das heutige Datum
CDate::CDate()
{ 
   struct tm* temp = NULL;
   time_t *temp_time = (time_t*) malloc(sizeof(time_t));

    if (!temp_time)
        return;

    *temp_time = time(NULL);
    temp = localtime(temp_time);
    setDate(temp->tm_mday, temp->tm_mon + 1, temp->tm_year + 1900);
}

// Konstruktor für beliebiges Datum  
CDate::CDate(int dd, int mm, int yyyy)
{
    setDate(dd, mm, yyyy);
}

void CDate::print()
{
    cout << setfill('0') << setw(2) << Day << "." << setw(2) << Month << "." << setw(2) << Year;
}

