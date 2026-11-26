#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "tools.h"
#include "caddress.h"

void CAddress::print()
{
    cout << Street << ' ' << Number << endl;

    cout << Zipcode << ' ' << Town;
}

string CAddress::getStreet()
{
    return Street;
}

string CAddress::getNumber()
{
    return Number;
}

string CAddress::getZipcode()
{
    return Zipcode;
}

string CAddress::getTown()
{
    return Town;
}

void CAddress::setStreet(string Street)
{
    this->Street = Street;
}

void CAddress::setNumber(string Number)
{
    this->Number = Number;
}

void CAddress::setZipcode(string)
{
    this->Zipcode = Zipcode;
}

void CAddress::setTown(string Town)
{
    this->Town = Town;
}

void CAddress::setAddress(string Street, string Number, string Zipcode, string Town)
{
    setStreet(Street);
    setNumber(Number);
    setZipcode(Zipcode);
    setTown(Town);
}

int CAddress::load(ifstream &file)
{
    if (!file)
    {
        cerr << "Datei ist nicht geöffnet";
        return -1;
    }

    string tag, line, value; 

    do 
    {
        getline(file, line);
        parseLine(line, tag, value);

        if (!tag.compare("<street>"))
            this->Street = value;

        if (!tag.compare("<number>"))
            this->Number = value;

        if (!tag.compare("<zipcode>"))
            this->Zipcode = value;

        if (!tag.compare("<town>"))
            this->Town = value;
    } while (tag.compare("</address>") && !file.eof());

    return 0;
}