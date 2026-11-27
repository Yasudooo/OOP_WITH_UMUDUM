#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "tools.h"
#include "cdate.h"
#include "ctime.h"
#include "clocation.h"
#include "caddress.h"
#include "cperson.h"
#include "cmedium.h"
#include "clibrary.h"
#include "clibrarypool.h"

CPerson *alloc_Mem_Person()
{
    CAddress dummy_address("dummy", "dummy", "dummy", "dummy");
    CDate dummy_date;

    // nothrow ensures that if memory cant allocate, that NULL is returned
    CPerson *new_element = new(nothrow) CPerson("dummy", dummy_address, dummy_date);

    return new_element;
}

CLibrary *alloc_Mem_Library()
{
    CDate dummy_date;
    CAddress dummy_address("dummy", "dummy", "dummy", "dummy");
    CPerson dummy_person("dummy", dummy_address, dummy_date);

    // nothrow ensures that if memory cant allocate, that NULL is returned  
    CLibrary *new_element = new(nothrow) CLibrary("dummy", dummy_address, &dummy_person);

    return new_element;
}

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

CLibraryPool::CLibraryPool(const char *filename)
{
    ifstream file; // ifstream ist zum lesen da 
    CLibrary *lib = NULL;
    CPerson *Customer = NULL;

    file.open(filename, ios::in);

    string line, tag, value; 

    if (!file)
    {
        cout << "Das öffnen der Datei hat nicht funktioniert.";
        return;
    }
    
    // gesamte Zeile eingelesen, inklusiv vom \n , also das offset landet direkt in der nächsten Zeile
    do
    {    
        getline(file, line);

        parseLine(line, tag, value);
        /*
        * every attribut of CLibraryPool means a case 
        * in dependence of what got read with getline, has to be called the load method 
        * or just assign  
        ********************************************************************************************
        * for the vectors:
        * treat them like arrays, assign and then increase index 
        * or
        * increase index and then assign 
        */

        /*
        * needed is a till_char for c++ to skip every cha to '<' (specific because of XML - file) 
        * till_char is used in parseLine
        */
    
        /*
         * load methods assign attributes NOT INITIALIZE,
         * so initialize with dummy values (or standard constructor)
        */
        
        if (!tag.compare("chairman"))
        {
            CAddress dummy_address("dummy", "dummy", "dummy", "dummy");
            CDate dummy_date;
            elPatron = new CPerson("dummy", dummy_address, dummy_date);
            elPatron->load(file); 
        }

        if (!tag.compare("name"))
            this->Büchereiverband = value;

        if (!tag.compare("library"))
        {
            lib = alloc_Mem_Library();

            if (lib)
            {
                lib->load(file);
                (this->libraryStores).push_back(lib);
            }
        }

        if (!tag.compare("customer"))
        {
            Customer = alloc_Mem_Person();

            if (Customer)
            {
                Customer->load(file);
                (this->Customer).push_back(Customer);
            }
        }
            

    } while ((!file.eof()) && (line.compare("</libraryPool>"))); // returns false if eof isn't reached

}

CLibraryPool::~CLibraryPool()
{
    CPerson *for_delete_person = NULL;
    CLibrary *for_delete_lib = NULL;
    // einfach der Reihe nach alle reservierten Speicherbereiche der Attribute freigeben 
    delete(elPatron);

    while (!libraryStores.empty())
    {
        for_delete_lib = libraryStores.back();
        libraryStores.pop_back();
        delete(for_delete_lib);
    }

    while (!Customer.empty())
    {
        for_delete_person = Customer.back();
        Customer.pop_back();
        delete(for_delete_person);
    }
}