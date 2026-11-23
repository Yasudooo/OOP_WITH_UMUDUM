#ifndef CLIBRARYPOOL_H

#define CLIBRARYPOOL_H

class CLibraryPool
{
	string Büchereiverband;
	CPerson *elPatron;
	vector<CLibrary *> libraryStores;
	vector<CPerson *> Customer;

public:
	CLibraryPool(string, CPerson *);
	CLibraryPool(char *);
	void add(CLibrary *);
	void add(CPerson *);
	void print();

	// Speichern (written by Umut):
	void load(std::ifstream &file);
	// std:ifstream ist der Datentyp einer mit Open geöffneten file. Und Differenzierung statt pointer
	// um nullpointer zu vermeiden. Die Differenzierung garantiert quasi ne File.
};

#endif
