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

int parseLine(const string &line, string &tag, string &value) // const weil wir fassen den line ja net an sondern kopieren nur raus.
{

	tag.clear();   // Beide stings einmal leeren (diese . funktionen sind aus der string header)
	value.clear(); // es gibt zeilen ohne value. Anhand von value = "" weiß man dann das es nur ein titel is ohne value.

	string text = till_char(line, '<'); // erstmal alle müllsachen vor dem < weg-aalen.

	// wir sind nun am <. von < bis > ist unser Titel.

	// sucht nach > und gibt den Index zurück als size_t
	size_t endTag = text.find('>');

	if (endTag == std::string::npos)
	{ // reine prüfung, falls kein > da ist, returnt er eine -1 weil fehler
		return -1;
	}

	tag = text.substr(1, endTag - 1); // substring -> schneidet eine gewünschte länge raus.
	// der erste Parameter also die 1, skippt das <. Und das endTag - 1 skippt das >. Wir bekommen die reine länge des titels.

	// Jetzt fehlt noch unser Value. Dieser ist zwischen > und </

	// erase löscht einf nur. Wir wollen halt NACH unser Titel. Also von 0 bis endTag+1 die chars rauslöschen
	text.erase(0, endTag + 1);

	// ab hier eig gleiches Spiel:
	size_t closeTag = text.find("</");

	if (closeTag != std::string::npos) // es gibt ja manche titel ohne value also kein -1 zurückgeben.
	{
		value = text.substr(0, closeTag); // ja wir nehmen das / mit um end und begin tags zu unterscheiden
		return 0;
	}
	else
	{
		return 0; // zum signalisieren das alles geklappt hat, auch wenns kein value gibt
	}
}

// alte tools die direkt mit cpp kompatibel :

// clearbuffer leider nötig weil alle anderen funktinen drauf aufbauen
void clearBuffer()
{
	char dummy;
	while (((dummy = getchar()) != '\n' && dummy != EOF))
		;
}

int askYesOrNo(char *Question) // Gibt bei Nein 0 aus und bei Ja eine 1
{
	int Bool = 0;
	char antwort;

	do
	{
		printf("%s", Question);
		scanf(" %c", &antwort);
		clearBuffer();
		if ((antwort == 'n') || (antwort == 'N') || (antwort == 'j') || (antwort == 'J'))
		{
			Bool = 0;
		}
		else
		{
			Bool = 1;
		}
	} while (Bool);
	if ((antwort == 'j') || (antwort == 'J'))
	{
		Bool = 1;
	}
	return Bool;
}

void clearScreen()
{
	system("clear");
}

void waitForEnter()
{
	printf("\n\nBitte eingabetaste druecken...\n");
	getchar();
}

void printLine(char Zeichen, int Anzahl)
{
	for (int i = 0; i <= Anzahl; i++)
	{
		printf("%c", Zeichen);
	}
}

void getNumber(char *print, int *zahl, int von, int bis)
{

	int eingabe;
	int check;
	int prüf = 0;

	do
	{
		printf("\n%s\n", print);

		char getChar;
		int Prüfung = 0;

		do
		{
			getChar = getchar();
			if (getChar == '\n')
			{
				clearScreen();
				printf("Bitte etwas eingeben!\n");
				printf("\n%s\n", print);
				Prüfung = 1;
			}
			else
			{
				ungetc(getChar, stdin);
				Prüfung = 0;
			}
		} while (Prüfung == 1);

		check = scanf("%d", &eingabe);
		clearBuffer();

		if (check != 1 || eingabe < von || eingabe > bis)
		{
			clearScreen();
			printf("Ungueltige Eingabe! Bitte eine Zahl zwischen %d und %d eingeben.\n", von, bis);
			prüf = 1;
		}
		else
		{
			prüf = 0;
		}

	} while (prüf == 1);

	*zahl = eingabe;
}
