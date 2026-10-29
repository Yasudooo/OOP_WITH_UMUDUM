#ifndef CADDRESS_H

#define CADDRESS_H

class CAddress
{
        string Street;
        string Number;
        string Zipcode;
        string Town;

    public:
        void print();
        CAddress(string Street, string Number, string Zipcode, string Town)
        : Street(Street), Number(Number), Zipcode(Zipcode), Town(Town) {}

        // set Methoden
        void setStreet(string);
        void setNumber(string);
        void setZipcode(string);
        void setTown(string);
        void setAddress(string, string, string, string);

        // get Methoden
        string getStreet();
        string getNumber();
        string getZipcode();
        string getTown();
};

#endif 
