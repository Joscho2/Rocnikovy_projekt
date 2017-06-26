#include "../../include/strategy/StrategyA.h"
#include "../../include/strategy/Bruteforce.h"

#include <set>
#include <iostream>

/**
 * Stratégia, ktorá overí, či je vôbec možné hrany ohodnotiť tak aby bol
 * výsledný tok v grafe nulový. Funguje len pre grupy v tvare Zn.
 */

StrategyA::StrategyA(vector<hrana> hrany, Grupa grupa, int pocet_vrcholov)
:Algoritmus(hrany, grupa, pocet_vrcholov){

	for(int i = 0; i < pocet_vrcholov; i++) otec.push_back(-1);
}

bool StrategyA::find(){

	//Funguje to len pre grupy v tvare Zn !
	if(grupa.getZ().size() != 1){
		cout<< "Túto metódu je možné použiť len pre grupy v tvare Zn!"<<endl;
		exit(0);
	}



	int index = 0; //index aktuálne spracovávanej hrany

	vector<hrana> novy_graf; //Vytvoríme si graf, ktorý bude v relácií
							//ekvivalencie s naším

	//Pokiaľ môžem pridať vrchol
	while(index < hrany.size()){
		if(find(hrany[index].zaciatok) != find(hrany[index].koniec)){
			//Spájame komponenty
			unionm(hrany[index].zaciatok, hrany[index].koniec);

			//Do nového grafu pridáme hranou s rovnakou hodnotou
			//ako v pôvodnom grafe
			novy_graf.push_back(hrany[index]);

		} else {
			//Hrane mimo kostry priradíme hodnotu 0
			hrana h {
						hrany[index].zaciatok,
						hrany[index].koniec,
						Prvok::getZero(grupa), //zakazana hodnota
						Prvok::getZero(grupa) //nejake ohodnotenie
					};

			//A pridáme ju do nového grafu
			novy_graf.push_back(h);
		}
		index++;
	}

	//Máme vytvorený graf, ideme skúsiť nájsť v ňom tok
	Bruteforce algoritmus(novy_graf, grupa, pocet_vrcholov);

	return algoritmus.find(false);
}


int StrategyA::find(int koho){
    if(otec[koho] != -1){
        if(otec[otec[koho]] != -1){
			//Vylepšenie, rovno všetkých pripojíme na otca a tým bude
			//budúce prehľadávanie v podstate konštantné
            int mojotec = find(otec[koho]);
            otec[koho] = mojotec;
			return mojotec;

        } else {
            return find(otec[koho]);
        }

     } else {
         return koho;
    }
}

void StrategyA::unionm(int a, int b){
    otec[find(b)] = find(a);
}
