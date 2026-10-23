#ifndef CLOCATION_H

#define CLOCATION_H


class CLocation
{
    string Section;
    string Rack;

    public:
    CLocation(); // Standard-Konstruktor
    CLocation(string, string);
    void print();

    // set Methoden
    void setSection(string);
    void setRack(string);

    // get Methoden 
    string getSection();
    string getRack();
};

#endif