//  Student:
//  Rolnummer:
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "positie.h"
#include <cstdlib>


ostream& operator<<(ostream& s,positie p)
{ return s;}

positie::positie(int kolom, int row) {
    this->row = row;
    this->kolom = kolom;
}
positie::positie(string s) {
    positie(
            (this->charToInt(s[0])),
            (s[1])
    );
}


int positie::charToInt(char c) {
    string characters = "abcdefgh";

    for (int i = 0; i < characters.length(); i++) {
        if (c == characters[i])
            return ++i;

        return -1;
    }
}

string positie::intToStr(int i) {
    return to_string("abcdefgh"[i - 1]);
}

string positie::str() {
    string partOne = this->intToStr(this->kolom);
    string partTwo = to_string(this->row);

    return partOne + partTwo;
}
