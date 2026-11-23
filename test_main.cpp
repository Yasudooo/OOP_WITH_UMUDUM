// Nur zum testen von Funktionen, ich teste hier einf nur kurz die parse funktion

#include <iostream>
#include <string>
#include "tools.h"

using namespace std;

int main()
{

	clearScreen();

	string testZeilen[] = {
		"   <City>Berlin</City>", // Normaler Wert mit Leerzeichen
		"   <Library>",			  // Start-Tag ohne Value
		"   </Library>",		  // End-Tag ohne Value
		"   "					  // Leere / kaputte Zeile (-1)
	};

	string tag, value;

	for (const string &line : testZeilen)
	{
		int status = parseLine(line, tag, value);
		cout << "Input:  \"" << line << "\"\n"
			 << "Status: " << status
			 << " | Tag: [" << tag << "]"
			 << " | Value: [" << value << "]\n"
			 << "----------------------------------------\n";
	}

	return 0;
}