#ifndef CDATE_H

#define CDATE_H

class CDate      
{
    //private:
        int Day, Month, Year;

    // Methoden
    public:
        CDate();              // Konstruktor für das aktuelle Datum
        CDate(int, int, int); // Konstruktor für variables Datum 
        void setDate(int, int, int);
        void print();
};

#endif
