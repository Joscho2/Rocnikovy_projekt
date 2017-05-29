#include "../include/Prvok.h"
#include <sstream>
#include <assert.h>
#include <iostream>


using namespace std;

Prvok::Prvok(Grupa z, string s)
:z(z)
{

	//Rozbijeme si vstupný string na jednotlivé "grupy"
	size_t pos = 0;
	stringstream ss;
	int toin;
	s += "x";
	while ((pos = s.find("x")) != string::npos) {

		string pom = s.substr(0, pos);

		stringstream ss;
	 	ss<<pom;
	 	ss>> toin;

		x.push_back(evaluate(toin, x.size()));

		s.erase(0, pos + 1);
	}
	assert(getG().getZ().size() == x.size());

	/*cout<< "Vytvoril som zo stringu: ";
	for(int i = 0; i < x.size(); i++){
		cout<< x[i] << " ";
	}
	cout<< "\n" <<endl;*/

}

Prvok::Prvok(Grupa z, vector<int> a)
:z(z)
{
	assert( getG().getZ().size() == a.size());
	for(int i = 0; i < a.size(); i++){
		x.push_back(evaluate(a[i], i));
	}

	/*cout<< "Vytvoril som z vectora: ";
	for(int i = 0; i < x.size(); i++){
		cout<< x[i] << " ";
	}
	cout<<endl;*/

}


vector<int> Prvok::operator+(const Prvok &p2) const{
	vector<int> result;
	for(int i = 0; i < getX().size(); i++){
		result[i] = evaluate(getX()[i] + p2.getX()[i], i);
	}
    return result;
}

void Prvok::operator+=(Prvok &p2) {
	for(int i = 0; i < getX().size(); i++){
		x[i]  = evaluate(getX()[i] + p2.getX()[i], i);
	}

}

void Prvok::operator-=(Prvok &p2) {
    for(int i = 0; i < getX().size(); i++){
		x[i]  = evaluate(getX()[i] - p2.getX()[i], i);
	}
}

bool Prvok::operator!=(const Prvok &p2) const {
	if(getX().size() != p2.getX().size()) return true;
	for(int i = 0; i < getX().size(); i++) if(getX()[i] != p2.getX()[i]){
		return true;
    	//cout<< getString() << " != " << p2.getString()<<endl;
    }
    //cout<< getString() << " == " << p2.getString()<<endl;
    return false;
}

Prvok Prvok::getZero(Grupa g){
	vector<int> temp;
	for(int i = 0; i < g.getZ().size(); i++){
		temp.push_back(0);
	}
	Prvok result(g, temp);
	return result;
}

Grupa Prvok::getG() const{
    return z;
}

vector<int> Prvok::getX() const{
    return x;
}

string Prvok::getString() {
	string result = "";
	for(int i = 0; i < getX().size(); i++){
		result += to_string(x[i]) + " ";
	}
	return result;
}



int Prvok::evaluate(const int e, const int index) const {
	if(e < 0){
		return getG().getZ()[index] + (e % getG().getZ()[index] );
	}
    return e % getG().getZ()[index] ;
}

//Iterator

void Prvok::Iterator::count(vector<int> a, int pos){
	if(pos == g.getZ().size()){
		/*cout<< "Ide sem: ";
		for(int i = 0; i < a.size(); i++){
			cout<< a[i] << " ";
		}
		cout<<endl;*/
		temp.push_back(a);
	} else {
		for(int i = 0; i < g.getZ()[pos]; i++){
			a[pos] = i;
			count(a, pos + 1);
		}
	}
}

Prvok::Iterator::Iterator(Grupa g)
:index(0), g(g)
{
	vector<int> hlpv;
	hlpv.resize(g.getZ().size());
	count(hlpv, 0);
	index = 0;
}

bool Prvok::Iterator::hasNext(){
	return (index < temp.size());
}

void Prvok::Iterator::next(){
	index++;
}

Prvok Prvok::Iterator::get(){
	Prvok tempPrvok(g, Iterator::temp[Iterator::index]);
	return tempPrvok;
}

Prvok::Iterator Prvok::getIt(Grupa g){
	Iterator it(g);
	return it;
}
