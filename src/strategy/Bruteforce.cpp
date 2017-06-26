#include "../../include/strategy/Bruteforce.h"
#include "../../include/Iterator.h"
#include <assert.h>
#include <iostream>

using namespace std;

Bruteforce::Bruteforce(vector<hrana> hrany, Grupa grupa, int pocet_vrcholov)
:Algoritmus(hrany, grupa, pocet_vrcholov){}

bool Bruteforce::kontrola(){

    vector<Prvok> vrchol;

    Prvok nullPrvok = Prvok::getZero(grupa);
    for(int i = 0; i < pocet_vrcholov; i++){
        vrchol.push_back(nullPrvok);
    }

    for(int i = 0; i < hrany.size(); i++){
        vrchol[hrany[i].zaciatok]-= hrany[i].prvok; //Vychádzajúca hrana, odčítame jej hodnotu
        vrchol[hrany[i].koniec]+= hrany[i].prvok; //Vchádzajúca hrana, pripočítavame jej hodnotu
    }

    for(int i = 0 ; i < pocet_vrcholov; i++){
        //if(vrchol[i] != Prvok::getZero(grupa)) return false; //Kompilator toto nezvlada
        for(int j : vrchol[i].getX()) if(j != 0) return false;
    }
    return true;
}

void Bruteforce::woodCut(int index){
	if(index == hrany.size()) {

	    if(kontrola()){
			najdene = true;
	    }

    } else {
		if(!najdene){
	        for(Iterator it(grupa); it.hasNext(); it.next()){
	        	Prvok tempPrvok = it.get();
	        	if(tempPrvok != hrany[index].zakazana_hodnota){
	        		hrany[index].prvok = tempPrvok;
	                woodCut(index + 1);
                    if(najdene) break;
	        	}
	        }
		}
    }
}

bool Bruteforce::find(){
	return find(true);
}

bool Bruteforce::find(bool skoncit){
    najdene = false;
    woodCut(0);

	if(skoncit && najdene){
		cout<< "Nájdený tok [z, do, ohodnotenie]: "<<endl;
		for(int i = 0; i < hrany.size(); i++){
			cout<< "[" << hrany[i].zaciatok << ", "
				<< hrany[i].koniec << ", ";
			for(int j : hrany[i].prvok.getX()) cout<< j << "x";
			cout<< "\b"  << "]" << endl;
		}
		exit(0);

	}

	return najdene;
}
