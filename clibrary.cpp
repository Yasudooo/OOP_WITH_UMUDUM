#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "cdate.h"
#include "ctime.h"
#include "clocation.h"
#include "caddress.h"
#include "cperson.h"
#include "cmedium.h"
#include "clibrary.h"

void CLibrary::print()
{
    // Daten über die Bibliothek
    cout << "Bücherei Filiale " << this->Name << endl;
    this->Address.print(); cout << '\n';
    cout << "Filialleiter: "; this->Manager->print(); cout << '\n';
    cout << "Es stehen " << this->Books.size() << " Medien zur Verfügung:\n\n";

    // Ausgabe der Medien die die Bibliothek hat
    for (unsigned long int i = 0 ; i < this->Books.size() ; i++)
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