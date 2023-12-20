#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

/*
Yeaseen Arafat created this.
*/

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
    void reallocate();

public:
     ArrayList();
     ArrayList(const ArrayList& other);
     ArrayList& operator=(const ArrayList& other);
    ~ArrayList();


     void add(const MultiType & element);
     const MultiType * gets(int index) const;
     int getSize() const;
     int getCapacity() const;
     void removeAtId(int id);
     void removeAll(int newCapacity);

     void move(int index1, int index2);
     void reverseArray();
     void printAvalue(int id) const;
     void printALL() const;


};


ArrayList::ArrayList() {
    arraySize = 2;
    currentSize = 0;
    data = new MultiType[arraySize];

}

//Copy Constructor
ArrayList::ArrayList(const ArrayList& other) {
    arraySize = other.arraySize;
    currentSize = other.currentSize;
    data = new MultiType[arraySize];

    for (int i = 0; i < currentSize; i++) {
        data[i] = other.data[i];
    }
}

// Assignment Operator
ArrayList& ArrayList::operator=(const ArrayList& other) {
    if (this != &other) { // Check for self-assignment
        delete[] data; // Release existing memory

        arraySize = other.arraySize;
        currentSize = other.currentSize;
        data = new MultiType[arraySize];

        for (int i = 0; i < currentSize; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}


ArrayList :: ~ArrayList() {
    delete []data;
};



void ArrayList::reallocate() {

    arraySize *= 2;
    MultiType * temp = new MultiType[arraySize];

    for (int i = 0; i < currentSize; i++) {

        temp[i] = data[i];
    }

    delete [] data;

    data = temp;

}


void ArrayList::add(const MultiType & element) {

     if (currentSize == arraySize) {
        try {
            reallocate();
        } catch (const bad_alloc& e) {
            // Handle the exception, maybe by resizing differently or propagating it.
            // For now, let's just print an error message.
            std::cerr << "Memory allocation error: " << e.what() << std::endl;
            return; // Do not proceed with adding the element
        }
    }

    data[currentSize] = element;
    currentSize++;

}



const MultiType * ArrayList::gets(int index) const {

    return (index >= 0 && index < currentSize) ? (data + index) : nullptr;
}


void ArrayList::removeAtId(int id) {

    if (id < currentSize-1 && id >= 0) {

        for (int i = id; i < currentSize -1; i++) {

            data[i] = data[i + 1];
        }
        currentSize--;
        arraySize--;
    }
    else cout<<"You are not in the valid location to remove"<<endl;

}

void ArrayList::removeAll(int newCapacity) {

    delete [] data;
    data = new MultiType[newCapacity];

    arraySize = newCapacity;
    currentSize = 0;
}


void ArrayList::move(int index1, int index2) {

    if (index1 >= 0 && index2 >= 0 &&
        index1 < currentSize  && index2 < currentSize ) {

        MultiType temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;

        cout<<"Successfuly switched "<<index1<<" and "<<index2<<endl;
    }
    else cout<<"You are not in the valid location to make a move"<<endl;
}

void ArrayList::reverseArray()
{
	for (int low = 0, high = currentSize - 1; low < high; low++, high--) {
		move(low, high);
	}
}


int ArrayList::getSize() const {

    return currentSize;
}

int ArrayList::getCapacity() const {

    return arraySize;
}


void ArrayList::printAvalue(int id) const{

    if(!(id >= 0 && id < currentSize)){
        cout << "Sorry! You are not permitted at this location"<<endl;
        return;
    }
 const MultiType& p = *gets(id);
	
    if(holds_alternative<int>(p)) {
      cout<<"Data Type: int ------  Data value: " << get<int>(p) << '\n';
    }
    else if(holds_alternative<string>(p)){
        cout<<"Data Type: string ------  Data value: " << get<string>(p) << '\n';
    }
    else if(holds_alternative<float>(p)){
        cout<<"Data Type: float ------  Data value: " << get<float>(p) << '\n';
    }
    else if(holds_alternative<double>(p)){
        cout<<"Data Type: double ------  Data value: " << get<double>(p) << '\n';
    }
   
}

void ArrayList::printALL() const{

    cout << endl;
    for(int i=0; i<currentSize; i++){
        printAvalue(i);
    }
}

#endif /* ARRAYLIST_H_ */
