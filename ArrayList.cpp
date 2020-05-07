#include "ArrayList.h"


int main(){

    ArrayList myList;

    myList.add(12);
    myList.add(12.345);
    myList.add(12.11f);
    myList.add("Its high time ...");
    myList.add(53);

    cout << "The capacity of the list is: " << myList.getCapacity() << endl;
    cout << "The size of the list is: " << myList.getSize() << endl;
    myList.printALL();

    cout<<endl;

    myList.printAvalue(2);

    cout<<endl;

    myList.removeAtId(0);

    cout << "The capacity of the list is: " << myList.getCapacity() << endl;
    cout << "The size of the list is: " << myList.getSize() << endl;
    myList.printALL();

    if(myList.move(0,2)) cout<<"Move is done successfully";
    else cout<<"Move is not applicable";

    myList.printALL();

    myList.reverseArray();

    myList.printALL();



}
