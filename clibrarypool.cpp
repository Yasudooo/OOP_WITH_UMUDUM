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
#include "clibrarypool.h"

CLibraryPool::CLibraryPool(string Büchereiverband, CPerson *elPatron)
: Büchereiverband(Büchereiverband), elPatron(elPatron)
{
}

void CLibraryPool::add(CPerson *Customer)
{
    if (Customer)
        this->Customer.push_back(Customer);
}

void CLibraryPool::add(CLibrary *Store)
{
    if (Store)
        this->libraryStores.push_back(Store);
}

void CLibraryPool::print()
{
    cout << this->Büchereiverband << '\n' ;
    cout << "Leitung "; this->elPatron->print();
    
    cout << "\nZum Büchereiverband gehören " << this->libraryStores.size() << " Filialen:\n\n";

    for (unsigned long int i = 0 ; i < this->libraryStores.size() ; i++)
    {
        this->libraryStores.at(i)->print();
        cout << '\n';
    }

    cout << "\nDer Buchereiverband hat " << this->Customer.size() << " Kunden:\n\n";

    for (unsigned long int i = 0 ; i < this->Customer.size() ; i++)
    {
        this->Customer.at(i)->print();
        cout << "\n\n"; 
    }
}

CLibraryPool::CLibraryPool(char *filename)
{
    ifstream file; // ifstream ist zum lesen da 

    file.open(filename, ios::in);

    string line; 

    if (!file)
    {
        cout << "Das öffnen der Datei hat nicht funktioniert.";
        return;
    }
    
    // gesamte Zeile eingelesen, inklusiv vom \n , also das offset landet direkt in der nächsten Zeile
    getline(file, line);
}