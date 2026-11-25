#ifndef CLOCATION_H

#define CLOCATION_H

class CLocation
{
	string Section;
	string Rack;

public:
	CLocation(); // Standard-Konstruktor
	CLocation(string, string);
	void print();

	// set Methoden
	void setSection(string);
	void setRack(string);

	// get Methoden
	string getSection();
	string getRack();

	// Speichern (written by Umut):
	int load(std::ifstream &file);
	// std:ifstream ist der Datentyp einer mit Open geöffneten file. Und Differenzierung statt pointer
	// um nullpointer zu vermeiden. Die Differenzierung garantiert quasi ne File.
};

#endif