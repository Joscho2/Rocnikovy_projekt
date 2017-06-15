#include <vector>
#include <string>
#include "Grupa.h"

#ifndef PRVOK_H
#define PRVOK_H

using namespace std;

//Trieda prvok predstavuje prvok grupy Zx, kde x je prirodzené číslo
class Prvok
{
    public:
        Prvok(Grupa z, string s); //Vytvorenie prvku zo stringu v tvare (int)x(int)x...(int)
        Prvok(Grupa z, vector<int> a); //Vytvorenie prvku z vectoru

        vector<int>  getX() const; //Aktuálna hodnota prvku (napríklad 3 ak som v grupe Zx, kde x > 3)
        Grupa getG() const; //Grupa ku ktorej prvok prislúcha

        static Prvok getZero(Grupa g); //Vráti "nulový" prvok pre danú grupu (0x0x...0)

        vector<int> operator +(const Prvok &p2) const;
        void operator +=(Prvok &p2);
		void operator -=(Prvok &p2);
        bool operator !=(const Prvok &p2) const;

        string getString(); //Pomocná metóda, vhodná na debugovanie, vracajúca textovú reprezentáciu prvku


    private:
        int evaluate(const int e, const int index) const; //Získavanie "správnych"/"základných" hodnôt podľa grupy

        Grupa z; //Grupa do ktorej patrí Prvok
        vector<int> x; //Uloženie si prvku

};

#endif // PRVOK_H
