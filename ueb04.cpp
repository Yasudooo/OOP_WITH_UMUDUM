#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "tools.h"
#include "cdate.h"
#include "ctime.h"
#include "clocation.h"
#include "caddress.h"
#include "cperson.h"
#include "cmedium.h"
#include "clibrary.h"
#include "clibrarypool.h"

int main()
{
   CLibraryPool LP("data.xml");

   LP.print();
   cout << endl;

   return 0;
}
