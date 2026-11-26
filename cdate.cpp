#include <ctime>
#include <iomanip>
#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <fstream>

using namespace std;

#include "cdate.h"
#include "tools.h"

void CDate::setDate(int dd, int mm, int yyyy)
{
	if (dd >= 1 && dd <= 31 && (mm + 1) >= 1 && (mm + 1) <= 12 &&
	    yyyy >= 1900 && yyyy <= 2099)
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
	struct tm *temp = NULL;
	time_t *temp_time = (time_t *)malloc(sizeof(time_t));

	if (!temp_time)
		return;

	*temp_time = time(NULL);
	temp = localtime(temp_time);
	setDate(temp->tm_mday, temp->tm_mon + 1, temp->tm_year + 1900);
}

// Konstruktor für beliebiges Datum
CDate::CDate(int dd, int mm, int yyyy) { setDate(dd, mm, yyyy); }

void CDate::print()
{
	cout << setfill('0') << setw(2) << Day << "." << setw(2) << Month << "."
	     << setw(2) << Year;
}


int CDate::load(ifstream &file)
{
	string tag, value, line;

	if (!file)
	{
		cerr << "Öffnen der Datei fehlgeschlagen.\n";
		return -1;
	}

	do 
	{
		getline(file, line);
		parseLine(line, tag, value);

		if (!tag.compare("<day>"))
			this->Day = stoi(value); // atoi but for strings

		if (!tag.compare("<month>"))
			this->Month = stoi(value);

		if (!tag.compare("<year>"))
			this->Year = stoi(value);

	} while ((!file.eof()) && (tag.compare("</date>")));
}