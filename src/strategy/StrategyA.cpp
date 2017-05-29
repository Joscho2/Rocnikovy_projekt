#include "../../include/strategy/StrategyA.h"

#include <set>
#include <iostream>

/**
 * Stratégia, ktorá overí, či je vôbec možné hrany ohodnotiť tak aby bol
 * výsledný tok v grafe nulový. Funguje len pre 1-zakazujúce funkcie.
 */

StrategyA::StrategyA(vector<hrana> hrany, Grupa grupa, int pocet_vrcholov)
:Algoritmus(hrany, grupa, pocet_vrcholov){

	for(int i = 0; i < pocet_vrcholov; i++) otec.push_back(-1);
}

bool StrategyA::find(){

	//Funguje to len pre 1-zakazujúce funkcie !
	if(grupa.getZ().size() != 1){
		cout<< "Túto metódu je možné použiť len na 1-zakazujúce funkcie!"<<endl;
		exit(0);
	}



	int index = 0; //index aktuálne spracovávanej hrany

	//Pokiaľ môžem pridať vrchol
	while(index < hrany.size()){
		if(find(hrany[index].zaciatok) != find(hrany[index].koniec)){
			//Spájame komponenty
			unionm(hrany[index].zaciatok, hrany[index].koniec);

		} else {
			//Túto hranu už nepotrebujeme, spájala by vrcholy ktoré sú už
			//v kostre. Je teda mimo kostry, potrebujeme overiť, či je
			//zakázaná hodnota nulová.
			if(hrany[index].zakazana_hodnota != Prvok::getZero(grupa)){
				return false;
			}
		}
		index++;
	}
	return true;
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
