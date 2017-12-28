//  Student:
//  Rolnummer:
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#ifndef SCHAKEN_POSITIE_H
#define SCHAKEN_POSITIE_H

#include <iostream>
using namespace std;

class positie {
public:
    positie(int kolom, int row);
    positie(string s);
    positie();
    string str();
    static int charToInt(char c);

protected:
    int kolom = 0;
    int row = 0;

private:
    string intToStr(int i);
};

// Eventueel kan je volgende operator definieren
// dan kan je makkelijk cout << p; doen van een
// positie p
ostream& operator<<(ostream& s,positie p);



#endif //SCHAKEN_POSITIE_H
