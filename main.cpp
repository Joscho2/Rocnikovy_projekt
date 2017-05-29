#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include "include/Grupa.h"
#include "include/Prvok.h"
#include "include/strategy/Algoritmus.h"
#include "include/strategy/Bruteforce.h"
#include "include/strategy/StrategyA.h"

using namespace std;

int pocet_vrcholov; //Určuje nám počet vrcholov aktuálneho grafu
int cislovane_od_jedna = 0; //Premenná ktorá nám určuje, či vrcholy grafu vo vstupe číslujeme od jedna (hodnota je 1)
							//alebo od 0 (hodnota je 0)
vector<hrana> hrany; //Reprezentácia grafu vo vectore hrán
Grupa grupa(""); //Pracujeme s grupou grupa
Algoritmus* algoritmus; //Smerník na konkrétny "algoritmus" (stratégiu), ktorý bude hľadať tok v grafe.
                        //Bude "inicializovaný" iba raz a o jeho vymazanie s v najhoršom
                        //prípade postará operačný systém.

int main(int argc, char* argv[])
{

    /* ---- Načítanie vstupu a uloženie si grafu do štruktúr ---- **/

    ifstream vstup;
    string slovo;
    vstup.open("vstup.txt");
    if(vstup.is_open()) {

        //Načítanie počtu vrcholov
        vstup >> slovo;
        pocet_vrcholov = stoi (slovo);

        //Zistenie danej grupy
        vstup >> slovo;
        //slovo.erase(0, 1);
        //grupaz = stoi (slovo);
        Grupa newGrupa(slovo);
        grupa = newGrupa;

        //Načítavanie hrán
        int vrchol, susediaci_vrchol;
        while(vstup >> slovo){
            vrchol = stoi (slovo);

            vstup >> slovo;
            susediaci_vrchol = stoi (slovo);

            vstup >> slovo; //Zakazana hodnota

            assert( (vrchol <= pocet_vrcholov - 1 + cislovane_od_jedna) &&
            		(vrchol >= 0 + cislovane_od_jedna) &&
                    (susediaci_vrchol <= pocet_vrcholov - 1 + cislovane_od_jedna) &&
                    (susediaci_vrchol >= 0 + cislovane_od_jedna));

            hrana temp	{	vrchol - cislovane_od_jedna,
            				susediaci_vrchol - cislovane_od_jedna,
            				Prvok(grupa, slovo),
            				Prvok::getZero(grupa)
            			};

            hrany.push_back(temp);
        }
        vstup.close();

        //Výber algoritmu na hľadanie toku podľa vstupných argumentov
        if(argc == 1){
        	//Default, bez argumentov je prehľadávanie hrubou silou
        	algoritmus = new Bruteforce(hrany, grupa, pocet_vrcholov);
        } else {

        	if(argc == 2){

        		if(string(argv[1]) == "-a"){
        			algoritmus = new StrategyA(hrany, grupa, pocet_vrcholov);

        		} else if (string(argv[1]) == "-b"){
                    //Bruteforce prehľadávanie (je to aj default)
                    algoritmus = new Bruteforce(hrany, grupa, pocet_vrcholov);
                }
        	}

        }

    } else {
        cout<< "Nastala chyba pri otváraní súboru" <<endl;
    }

    /* ---- Koniec načítavania vstupu a ukladania si grafu do štruktúr ---- */



    /* ---- Spúšťanie prehľadávania ---- */

    if(algoritmus != NULL){
	    if(!algoritmus->find()) cout<< "Tok neexistuje." <<endl;
        else cout<< "Nejaký tok existuje." <<endl;
	} else {
		cout<< "Zle uvedené argumenty!"<<endl;
	}

	/* ---- Koniec prehľadávania ---- */

    delete algoritmus;
}
