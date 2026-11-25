#ifndef TOOLS_H

#define TOOLS_H

string till_char(string line, char wanted);

// Parse-Funktion -> wandelt eine Zeile in Tag und value um. Also z.b "   <City>Berlin</City>", '<' zu tag = City, value = Berlin
int parseLine(const string &line, string &tag, string &value);

// alte tools die direkt mit cpp kompatibel sind :

/*******************************************************
 * clearbuffer
 * leert den Tastaturpuffer
 * Parameter: keine
 * Ergebnis: nichts
 ********************************************************/
void clearBuffer();

/*******************************************************
 * askYesOrNo
 * fragt den Nutzer nach ob das Programm wiederholt werden soll
 * Parameter: Eine Frage bzw Zeichenkette
 * Ergebnis: Wahrheitswert (0 oder 1)
 ********************************************************/
int askYesOrNo(char *Question);

/*******************************************************
 * waitForEnter
 * warte bis der Benutzer etwas eingibt
 * Parameter: keine
 * Ergebnis: keine
 ********************************************************/
void waitForEnter();

/*******************************************************
 * clearScreen
 * cleart den Screen xD
 * Parameter: keine
 * Ergebnis: keine
 ********************************************************/
void clearScreen();

void printLine(char Zeichen, int Anzahl);

/*******************************************************
 * getText
 * fragt user nach einem Text und schreibt diese in Parameter "Zeichenkette"
 * Daher als doppelten Zeiger geben.
 * Parameter: Eingabeaufforderung, Max_Zeichen, Ist keine Eingabe erlaubt? (leer) -> 0 nein, 1->ja
 * von, bis
 * Ergebnis: keine
 ********************************************************/

void getNumber(char *print, int *zahl, int von, int bis);
#endif