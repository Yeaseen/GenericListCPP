#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <variant>
using namespace std;

using MultiType = variant<int, string, float, double>;

class ArrayList {

private:
    int arraySize;
    int currentSize;
    MultiType *data = nullptr;

public:
    ArrayList();
    ~ArrayList();

     void add(const MultiType & element);
     const MultiType * gets(int index) const;
     int getSize() const;
     void printAvalue(int id);

};


ArrayList::ArrayList() {
    arraySize = 10;
    currentSize = 0;
    data = new MultiType[arraySize];

}

ArrayList :: ~ArrayList() {
    delete []data;
};



void ArrayList::add(const MultiType & element) {


    data[currentSize] = element;
    currentSize++;

}



const MultiType * ArrayList::gets(int index) const {

    return (index >= 0 && index < currentSize) ? (data + index) : NULL;
}


int ArrayList::getSize() const {

    return currentSize;
}


void ArrayList::printAvalue(int id){

    if(!(id >= 0 && id < currentSize)){
        cout << "Sorry! You are not permitted at this location"<<endl;
        return;
    }
    MultiType p = *gets(id);
    if(holds_alternative<int>(p)) {
      cout << get<int>(p) << '\n';
    }
    else if(holds_alternative<string>(p)){
        cout << get<string>(p) << '\n';
    }
    else if(holds_alternative<float>(p)){
        cout << get<float>(p) << '\n';
    }
    else if(holds_alternative<double>(p)){
        cout << get<double>(p) << '\n';
    }

}

#endif /* ARRAYLIST_H_ */
