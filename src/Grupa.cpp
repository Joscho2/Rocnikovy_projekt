#include "../include/Grupa.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Grupa::Grupa(){} //Defaultný konštruktor

Grupa::Grupa(string s) {
	//Rozbijeme si vstupný string na jednotlivé "grupy"
	size_t pos = 0;
	stringstream ss;
	int toin;
	s += "x";
	while ((pos = s.find("x")) != string::npos) {

		string pom = s.substr(0, pos);
		pom.erase(0, 1); //Odrežeme "Z"

		stringstream ss;
	 	ss<<pom;
	 	ss>> toin;
		z.push_back(toin);

		s.erase(0, pos + 1);
	}


	/*cout<< "Grupa: ";
	for(int i = 0; i < z.size(); i++){
		cout << z[i] << " ";
	}
	cout<<endl;*/

}

Grupa::Grupa(vector<int> a){
	for(int i = 0; i < a.size(); i++){
		getZ().push_back(a[i]);
	}
}

vector<int> Grupa::getZ(){
	return z;
}
