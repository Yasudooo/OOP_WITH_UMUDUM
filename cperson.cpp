#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "cdate.h"
#include "ctime.h"
#include "caddress.h"
#include "cperson.h"
#include "tools.h"

void CPerson::print()
{
	if (!Name.compare("dummy"))
	{
		return;
	}
	cout << Name << endl;

	Address.print();
	cout << '\n';
	Birthday.print();
}

void CPerson::setName(string Name)
{
	this->Name = Name;
}

void CPerson::setAddress(CAddress Address)
{
	this->Address = Address;
}

void CPerson::setBirthday(CDate Birthday)
{
	this->Birthday = Birthday;
}

string CPerson::getName()
{
	return Name;
}

CAddress CPerson::getAddress()
{
	return Address;
}

CDate CPerson::getBirthday()
{
	return Birthday;
}

CPerson::CPerson(string Name, CAddress &Address, CDate &Birthday)
	: Name(Name), Address(Address), Birthday(Birthday)
{
	// die Initialisierungsliste übersetzt bedeutet: Nehme vom Parameter die Werte und weise sie dem Attribut "Address" zu

	// setName(Name);
	//(this->Address).setAddress(Address);
	// setBirthday(Birthday);
}

CPerson::~CPerson()
{
	if (!Name.compare("dummy"))
	{
		return;
	}
	cout << "Die Person " << this->Name << " gibt es nicht mehr.\n";
}

int CPerson::load(std::ifstream &file)
{
	if (!file)
	{
		cerr << "Die Datei ist nicht geöffnet.\n";
		return -1;
	}

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
		else if (tag == "birthday")
		{
			this->Birthday.load(file);
		}

		// there are 3 types of people:
		// 1. customer
		// 2. managaer
		// 3. chairman
		// so in conclusion the do while loop has to check for everyone (bc it can be anyone of them)
		// actually in data.xml the 3 types of people are categorized with <person> </person>, so it's unnecessary,
		// to check for everyone (to lazy to change it)
	} while ((!file.eof()) && (tag.compare("/customer")) && (tag.compare("/chairman")) && (tag.compare("/manager")));

	return 1;
}