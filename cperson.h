#ifndef CPERSON_H

#define CPERSON_H

class CPerson
{
	string Name;
	CAddress Address;
	CDate Birthday;

public:
	// Konstruktoren
	CPerson(string Name, CAddress &Address, CDate &Birthday);

	// Dekonstruktor
	~CPerson();

	// sonstige Methoden
	void print();

	// set Methoden
	void setName(string);
	void setAddress(CAddress);
	void setBirthday(CDate);

	// get Methoden
	string getName();
	CAddress getAddress();
	CDate getBirthday();

	// Speichern (written by Umut):
	void load(std::ifstream &file);
	// std:ifstream ist der Datentyp einer mit Open geöffneten file. Und Differenzierung statt pointer
	// um nullpointer zu vermeiden. Die Differenzierung garantiert quasi ne File.
};

#endif