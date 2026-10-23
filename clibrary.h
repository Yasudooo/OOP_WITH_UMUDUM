#ifndef CLIBRARY_H

#define CLIBRARY_H

class CLibrary
{
        string Name;
        CAddress Address;
        CPerson *Manager;
        vector<CMedium*> Books;

    public:
        CLibrary(string, CAddress, CPerson *);
        void add(CMedium*);
        void print();
};

#endif