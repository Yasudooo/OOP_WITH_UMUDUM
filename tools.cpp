#include <string>
#include <cstdlib>

using namespace std;

#include "tools.h"

string till_char(string line, char wanted)
{
    /*
     * idea:
     *
     * find the given char index and copy the string from the index then
     * and return the copy
    */

    size_t index = line.find(wanted);
    char *copy_p = (char *) malloc(line.length() + 1), *resett = NULL;
    string copyString;

    

    // didnt find the char => returns npos
    if (string::npos == index)
    {
        free(copy_p);
        return "\0";
    }
    
    line.copy(copy_p, line.length());
    resett = copy_p;

    // insert the \0 because copy doesnt add it 
    /*
     * the index where i have to assign the \0 is at 
     *
     * 
     *  */
    *(copy_p + line.length()) = '\0';

    while ((*copy_p != wanted) && *copy_p)
    {
        copy_p +=1;
    }

    copyString = copy_p;

    free(resett);
    resett = copy_p = NULL;

    return copyString;
}