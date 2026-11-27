#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "cdate.h"
#include "ctime.h"
#include "clocation.h"
#include "caddress.h"
#include "cperson.h"
#include "cmedium.h"
#include "clibrary.h"
#include "tools.h"

void CLibrary::print()
{
	// Daten über die Bibliothek
	cout << "Bücherei Filiale " << this->Name << endl;
	this->Address.print();
	cout << '\n';
	cout << "Filialleiter: ";
	this->Manager->print();
	cout << '\n';
	cout << "Es stehen " << this->Books.size() << " Medien zur Verfügung:\n\n";

	// Ausgabe der Medien die die Bibliothek hat
	for (unsigned long int i = 0; i < this->Books.size(); i++)
	{
		cout << "Medium Nr. " << i + 1 << '\n';
		this->Books.at(i)->print();
		cout << '\n';
	}
}

CLibrary::CLibrary(string Name, CAddress Address, CPerson *Person)
	: Name(Name), Address(Address), Manager(Person) {}

void CLibrary::add(CMedium *Mediumprt)
{
	if (Mediumprt)
		this->Books.push_back(Mediumprt);
}

int CLibrary::load(std::ifstream &file)
{
	string line = "";  // Variable für eingelesene Zeile
	string tag = "";   // Variable für gefundenden <Titel>
	string value = ""; // Variable für gefundenen >Wert<

	do
	{
		getline(file, line); // Zeile einlesen

		parseLine(line, tag, value);

		if (tag == "name") // nur in kleinbuchstaben weil parseLine alles umwandelt
		{
			this->Name = value;
		}
		else if (tag == "address")
		{
			this->Address.load(file);
		}
		else if (tag == "person")
		{
			this->Manager->load(file);
		}
		else if (tag == "medium")
		{
			CMedium *pMedium = new CMedium("", "", CLocation("", ""), 0, (CMedium::eStatus)0); // Speicher reservieren
			pMedium->load(file);															   // File sachen laden
			this->Books.push_back(pMedium);													   // Unser neuer Medium an den vektor dranhängen hinten
		}
		else
		{
			return -1;
		}
	} while ((!file.eof()) && (tag.compare("/library")));
	return 1;
}

CLibrary::~CLibrary()
{
	CMedium *for_delete_books = NULL;

	delete (Manager);

	for (unsigned int i = 0; i < Books.size(); i++)
	{
		for_delete_books = Books.back();
		Books.pop_back();
		delete (for_delete_books);
	}
}