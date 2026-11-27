#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "tools.h"
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

int CLocation::load(ifstream &file)
{
    if (!file)
    {
        cerr << "Die Datei ist nicht geöffnet.\n";
        return -1;
    }

    string tag, value, line;

    do 
    {
        getline(file, line);
        parseLine(line, tag, value);

        if (!tag.compare("section"))
            this->Section = value;

        if (!tag.compare("rack"))
            this->Rack = value;

    } while ((tag.compare("/location")) && (!file.eof()));

    return 0;
}