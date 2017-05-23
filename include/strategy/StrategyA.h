#ifndef STRATEGYA_H
#define STRATEGYA_H

#include <vector>
#include "Algoritmus.h"

class StrategyA: public Algoritmus {
	public:
		StrategyA(std::vector<hrana> hrany, Grupa grupa, int pocet_vrcholov);
		bool find();
	private:
		
};

#endif //STRATEGYA_H
