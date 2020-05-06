#include "ArrayList.h"


int main(){

    ArrayList myList;
    myList.add(12);
    myList.add(12.345);
    myList.add(12.11f);
    myList.add("Its high time ...");
    cout << "The size of the list is: " << myList.getSize() << endl;
    myList.printAvalue(0);
    myList.printAvalue(1);
    myList.printAvalue(2);
    myList.printAvalue(3);


}
