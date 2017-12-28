//  Student:
//  Rolnummer:
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "game.h"
#include "positie.h"
#include "chessboard.h"
#include "mainwindow.h"

map<string, schaakStuk*> schaakStukken;

game::game() {}

game::~game() {}

// Zet het bord klaar; voeg de stukken op de jusite plaats toe
void game::setStartBord() {
   scene->setInitialPositions();
}

// Verplaats stuk s naar positie p
// Als deze move niet mogelijk is, wordt false teruggegeven
// en verandert er niets aan het schaakbord.
// Anders wordt de move uitgevoerd en wordt true teruggegeven
bool game::move(schaakStuk* s, positie p) {
    string currentPosition = mapChessToPosition(s).str();
    positie newPosition = p;

    schaakStukken.erase(currentPosition);
    schaakStukken[newPosition.str()] = s;

    return true;
}

// Geeft true als kleur schaak staat
bool game::schaak(zw kleur) {
    return false;
}

// Geeft true als kleur schaakmat staat
bool game::schaakmat(zw kleur) {
    return false;
}

// Geeft true als kleur pat staat
// (pat = geen geldige zet mogelijk, maar kleur staat niet schaak;
// dit resulteert in een gelijkspel)
bool game::pat(zw kleur) {
    return false;
}


//Inverses map search
positie game::mapChessToPosition(schaakStuk* s) {
    for (auto i : schaakStukken)
        if (i.second == s)
            return i.first;
}