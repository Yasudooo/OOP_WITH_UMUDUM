#include <iostream>
#include <string>

using namespace std;

#include "clocation.h"
#include "cmedium.h"

void CMedium::print() {
  cout << "Titel:    " << this->Title << endl;
  cout << "Signatur: " << this->Signature << endl;
  Location.print();
  cout << '\n';
  cout << "FSK:      freigegeben ab " << this->ageRating << " Jahren" << endl;
  cout << "Status:   "
       << ((this->Status & verfuegbar)    ? "verfuegbar"
           : (this->Status & ausgeliehen) ? "ausgeliehen"
           : (this->Status & bestellt)    ? "bestellt"
                                          : "reserviert");
}

string CMedium::getTitle() { return this->Title; }

string CMedium::getSignature() { return this->Signature; }

CLocation CMedium::getLocation() { return this->Location; }

int CMedium::get_ageRating() { return this->ageRating; }

string CMedium::getStatus() {
  return (this->Status & verfuegbar)    ? "verfuegbar"
         : (this->Status & ausgeliehen) ? "ausgeliehen"
         : (this->Status & bestellt)    ? "bestellt"
                                        : "reserviert";
}
 
void CMedium::setTitle(string Title) { this->Title = Title; }

void CMedium::setSignature(string Signature) { this->Signature = Signature; }

void CMedium::setLocation(CLocation Location) { this->Location = Location; }

void CMedium::set_ageRating(int ageRating) { this->ageRating = ageRating; }

// diese Methode wird aufgeschoben ; kein bock das jetzt zu machen
/*void CMedium::setStatus(eStatus Status)
{
    //this->Status |= Status;
}*/

CMedium::~CMedium() {
  cout << "Das Objekt " << this->Title << " wurde vernichtet.\n";
}

CMedium::CMedium(string Title, string Signature, CLocation Location,
                 int ageRating, CMedium::eStatus Status)
    : Title(Title), Signature(Signature), Location(Location),
      ageRating(ageRating), Status(Status) {}
