#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "clocation.h"
#include "cmedium.h"
#include "tools.h"

void CMedium::print()
{
	cout << "Titel:    " << this->Title << endl;
	cout << "Signatur: " << this->Signature << endl;
	Location.print();
	cout << '\n';
	cout << "FSK:      freigegeben ab " << this->ageRating << " Jahren" << endl;
	cout << "Status:   "
		 << ((this->Status & verfuegbar)	? "verfuegbar"
			 : (this->Status & ausgeliehen) ? "ausgeliehen"
			 : (this->Status & bestellt)	? "bestellt"
											: "reserviert");
}

string CMedium::getTitle() { return this->Title; }

string CMedium::getSignature() { return this->Signature; }

CLocation CMedium::getLocation() { return this->Location; }

int CMedium::get_ageRating() { return this->ageRating; }

string CMedium::getStatus()
{
	return (this->Status & verfuegbar)	  ? "verfuegbar"
		   : (this->Status & ausgeliehen) ? "ausgeliehen"
		   : (this->Status & bestellt)	  ? "bestellt"
										  : "reserviert";
}

void CMedium::setTitle(string Title) { this->Title = Title; }

void CMedium::setSignature(string Signature) { this->Signature = Signature; }

void CMedium::setLocation(CLocation Location) { this->Location = Location; }

void CMedium::set_ageRating(int ageRating) { this->ageRating = ageRating; }

// diese Methode wird aufgeschoben ; kein bock das jetzt zu machen
/*void CMedium::setStatus(eStatus Status)
{
	//this->Status |= Status;
}*/

CMedium::~CMedium()
{
	cout << "Das Objekt " << this->Title << " wurde vernichtet.\n";
}

CMedium::CMedium(string Title, string Signature, CLocation Location,
				 int ageRating, CMedium::eStatus Status)
	: Title(Title), Signature(Signature), Location(Location),
	  ageRating(ageRating), Status(Status) {}

int CMedium::load(std::ifstream &file)
{

	string line = "";  // Variable für eingelesene Zeile
	string tag = "";   // Variable für gefundenden <Titel>
	string value = ""; // Variable für gefundenen >Wert<

	do 
	{
		getline(file, line); // Zeile einlesen

		parseLine(line, tag, value);

		if (tag == "title") // nur in kleinbuchstaben weil parseLine alles umwandelt
		{
			this->Title = value;
		}
		else if (tag == "signature")
		{
			this->Signature = value;
		}
		else if (tag == "location")
		{
			this->Location.load(file);
		}
		else if (tag == "fsk")
		{
			this->ageRating = stoi(value);
		}
		else if (tag == "status")
		{
			if (stoi(value) == 1)
			{
				this->Status = CMedium::verfuegbar;
			} // noch net fertig

			if (stoi(value) == 2)
				this->Status = CMedium::ausgeliehen;

			if (stoi(value) == 4)
				this->Status = CMedium::bestellt;

			if (stoi(value) == 8)
				this->Status = reserviert;
		}
		else
		{
			return -1;
		}
	} while ((!file.eof()) && (tag.compare("/medium")));

	return 1;
}