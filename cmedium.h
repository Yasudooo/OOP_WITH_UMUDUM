#ifndef CMEDIUM_H

#define CMEDIUM_H

class CMedium
{
    public:
        /*
        * die Namen im enum werden in 2er Schritten (bzw in 2er Potenzen angegeben), weil 
        * der Status mehrere Zustände haben soll gleichzeitig und ist möglich wenn die Namen dann 
        * in 2er Potenzen sind, weil jeder Name steht für 1 Bit von der gesamten Zahl und mit dem 
        * bitweisen ODER (Pipe Symbol | ) ist das realisierbar 
        */
        typedef enum
        {
            verfuegbar = 1, 
            ausgeliehen = 2,
            bestellt = 4,
            reserviert = 8
        }eStatus;

        // Konstruktor 
        CMedium(string, string, CLocation, int, CMedium::eStatus);

        // Dekonstruktor (ein Weiser Mann sagte mal: es kann nur einen geben)
        ~CMedium();

        // print Methode
        void print();

        // get Methoden
        string getTitle();
        string getSignature();
        CLocation getLocation();
        int get_ageRating();
        string getStatus(); // soll keine Zahl sondern wirklich den Status als string zurückgeben 
        
        // set Methoden
        void setTitle(string);
        void setSignature(string);
        void setLocation(CLocation);
        void set_ageRating(int);
        void setStatus(eStatus); // wird mit dem bitweisen ODER (also dem Pipe Symbol | )realisiert


    protected:
        string Title;
        string Signature;
        CLocation Location;
        int ageRating;
        eStatus Status;
};

#endif