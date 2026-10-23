#include <stdio.h>  
#include <iostream>
#include <ctime>
#include <malloc.h> 
#include <iomanip>


using namespace std;

#include "ctime.h"

// halloooooooooooooooo herr kempfer
// man munkelt es gibt ein weihnachts special ? :=)

/*
 * ich habe im nachhinein gemerkt, dass die Attribute vom Objekt 
 * und die übergebenen Parameter an den Konstruktor identisch sind,
 * also haben die Parameter nun kleine Buchstaben und die Attribute 
 * beginnen mit Großbuchstaben 
*/


void CTime::setTime(int h, int min, int sec)
{
    if (h >= 0 && h <= 23 && min >= 0 && min <= 59 && sec >= 0 && sec <= 59)
    {
        Sec = sec;
        Min = min;
        H = h; 
    }
    else 
    {
        Sec = Min = H = 0;
    }
}

// Konstruktor für die aktuelle Zeit 
CTime::CTime()
{
    struct tm* temp = NULL;
    time_t *temp_time = (time_t*) malloc(sizeof(time_t));

    if (!temp_time)
        return;


    time(temp_time);

    temp = localtime(temp_time);



    setTime(temp->tm_hour, temp->tm_min, temp->tm_hour);
}

// Konstruktor für beliebige Zeit
CTime::CTime(int h, int min, int sec)
{
    setTime(h, min, sec);
}

void CTime::print()
{
    cout << setfill('0') << setw(2) << H << ":" << setw(2) << Min << ":" << setw(2) << Sec << endl;
}