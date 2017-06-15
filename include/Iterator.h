#include <vector>

#include "Prvok.h"

using namespace std;

class Iterator{ //Iterátor na prechádzanie prvkov grupy, je vytváraný static metódou getIt()
    public:
        Iterator(Grupa g);
        bool hasNext();
        void next();
        Prvok get();
    private:
        void count(vector<int> a, int pos);
        int index;
        vector<vector<int>>  temp;
        Grupa g;
};
