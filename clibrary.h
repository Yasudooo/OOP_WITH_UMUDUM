#ifndef CLIBRARY_H

#define CLIBRARY_H

class CLibrary
{
	string Name;
	CAddress Address;
	CPerson *Manager;
	vector<CMedium *> Books;

public:
	CLibrary(string, CAddress, CPerson *);
	~CLibrary();
	void add(CMedium *);
	void print();

	// Speichern (written by Umut):
	int load(std::ifstream &file);
	// std:ifstream ist der Datentyp einer mit Open geöffneten file. Und Differenzierung statt pointer
	// um nullpointer zu vermeiden. Die Differenzierung garantiert quasi ne File.
};

#endif