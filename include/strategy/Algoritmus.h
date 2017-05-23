#ifndef ALGORITMUS_H
#define ALGORITMUS_H

#include <vector>
#include "../Prvok.h"
#include "../Grupa.h"
#include "../../src/Global.cpp"

/* Abstratkná trieda slúžiaca na ukladanie 
** zvoleného "algoritmu" pre hľadanie toku v grafe */
class Algoritmus{
	public:
		Algoritmus(std::vector<hrana> hrany, Grupa grupa, int pocet_vrcholov);
		virtual bool find() = 0;
		
		std::vector<hrana> hrany;
		int pocet_vrcholov;
		Grupa grupa;
};

#endif //ALGORITMUS_H
