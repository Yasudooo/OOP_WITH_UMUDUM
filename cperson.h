#ifndef CPERSON_H

#define CPERSON_H

//#include "caddress.h"
//#include "cdate.h"
class CLocation;
class CDate;
class CAddress;

class CPerson
{
    string Name;
    CAddress Address;
    CDate Birthday;

    public:
    // Konstruktoren
    CPerson(string Name, CAddress &Address, CDate &Birthday);

    // Dekonstruktor
    ~CPerson();

    // sonstige Methoden
    void print();

    // set Methoden
    void setName(string);
    void setAddress(CAddress);
    void setBirthday(CDate);

    // get Methoden
    string getName();
    CAddress getAddress();
    CDate getBirthday();
};

#endif