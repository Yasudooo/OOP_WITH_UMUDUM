#ifndef CDATE_H

#define CDATE_H

class CDate
{
	// private:
	int Day, Month, Year;

	// Methoden
public:
	CDate();			  // Konstruktor für das aktuelle Datum
	CDate(int, int, int); // Konstruktor für variables Datum
	void setDate(int, int, int);
	void print();
	void load(std::ofstream &file);

	// Speichern (written by Umut):
	void load(std::ifstream &file);
	// std:ifstream ist der Datentyp einer mit Open geöffneten file. Und Differenzierung statt pointer
	// um nullpointer zu vermeiden. Die Differenzierung garantiert quasi ne File.
};

#endif
