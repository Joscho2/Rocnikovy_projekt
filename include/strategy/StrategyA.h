#ifndef STRATEGYA_H
#define STRATEGYA_H

#include <vector>
#include "Algoritmus.h"

using namespace std;

class StrategyA: public Algoritmus {
	public:
		StrategyA(vector<hrana> hrany, Grupa grupa, int pocet_vrcholov);
		bool find();
	private:
		vector<int> otec;
		int find(int koho); //Jednoduchý UNION-FIND
		void unionm(int a, int b);

};

#endif //STRATEGYA_H
