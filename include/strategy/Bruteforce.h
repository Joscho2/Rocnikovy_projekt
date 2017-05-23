#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <vector>
#include "Algoritmus.h"

class Bruteforce: public Algoritmus {
	public:
		Bruteforce(std::vector<hrana> hrany, Grupa grupa, int pocet_vrcholov);
		bool find();
	private:
		bool kontrola();//Funkcia kontrola zisťuje, či je ohodnotenie hrán správne. Správne zanemená,
						//že súčet ohodnotení vchádzajúich a vychádzajúcich hrán pre každý vrchol je rovný nule
						
		void woodCut(int index);//Backtrack procedúra skúšajúca všetky ohodnotenia vrcholov,
		                        //prvé nájdené ohodnotenie spĺňajúce zadanie vypíše a skončí program
};

#endif //BRUTEFORCE_H
