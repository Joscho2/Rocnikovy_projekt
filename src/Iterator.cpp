#include "../include/Iterator.h"

//Iterator

void Iterator::count(vector<int> a, int pos){
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

Iterator::Iterator(Grupa g)
:index(0), g(g)
{
	vector<int> hlpv;
	hlpv.resize(g.getZ().size());
	count(hlpv, 0);
	index = 0;
}

bool Iterator::hasNext(){
	return (index < temp.size());
}

void Iterator::next(){
	index++;
}

Prvok Iterator::get(){
	Prvok tempPrvok(g, Iterator::temp[Iterator::index]);
	return tempPrvok;
}
