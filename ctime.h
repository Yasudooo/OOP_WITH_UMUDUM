#ifndef CTIME_H

#define CTIME_H

class CTime
{
	int Sec, Min, H;

public:
	void print();
	CTime();
	CTime(int, int, int Sec = 0);
	void setTime(int, int, int Sec = 0);

	// Speichern (written by Umut):
	void load(std::ifstream &file);
	// std:ifstream ist der Datentyp einer mit Open geöffneten file. Und Differenzierung statt pointer
	// um nullpointer zu vermeiden. Die Differenzierung garantiert quasi ne File.
};

#endif
