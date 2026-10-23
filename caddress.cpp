#include <iostream>
#include <string>

using namespace std;

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

