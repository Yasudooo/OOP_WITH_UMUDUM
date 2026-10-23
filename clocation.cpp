#include <iostream>
#include <string>

using namespace std;

#include "cdate.h"
#include "caddress.h"
#include "cperson.h"
#include "clocation.h"

void CLocation::setSection(string Section)
{
    this->Section = Section;
}

void CLocation::setRack(string Rack)
{
    this->Rack = Rack;
}

string CLocation::getSection()
{
    return this->Section;
}

string CLocation::getRack()
{
    return this->Rack;
}

CLocation::CLocation()
{
    setSection("Buero");
    setRack("Fach zum Einsortieren");
}

void CLocation::print()
{
    cout << "Abteilung: " << Section << "; " << "Regal: " << Rack; 
}

CLocation::CLocation(string Section, string Rack)
{
    setSection(Section);
    setRack(Rack);
}