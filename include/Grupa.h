#include <string>
#include <vector>

#ifndef GRUPA_H
#define GRUPA_H


using namespace std;

class Grupa
{
	public:
		Grupa();
		Grupa(string s); //Vytvorenie grupy zo stringu v tvare Z(int)xZ(int)x...Z(int)
		Grupa(vector<int> a);//Vytvorenie grupy z vectoru
		vector<int> getZ();//Získanie grupy v reprezentácií vo vectore
	private:
		vector<int> z;
		
};


#endif // GRUPA_H
