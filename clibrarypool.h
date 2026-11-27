#ifndef CLIBRARYPOOL_H

#define CLIBRARYPOOL_H

class CLibraryPool
{
	string Büchereiverband;
	CPerson *elPatron;
	vector<CLibrary *> libraryStores;
	vector<CPerson *> Customer;

public:
	CLibraryPool(string, CPerson *);
	CLibraryPool(const char *);
	~CLibraryPool();
	void add(CLibrary *);
	void add(CPerson *);
	void print();
	void free_mem();
};

#endif
