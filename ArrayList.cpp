#include "ArrayList.h"


int main(){

    // Create an ArrayList instance
    ArrayList originalList;
    originalList.add(42);
    originalList.add("Hello");
    originalList.printAvalue(1);
    originalList.add(3.14);
    originalList.add(2.79f);
    cout << "Original List Size: " << originalList.getSize() << "\n";
    cout << "The capacity of Original List is: " << originalList.getCapacity() << endl;

    // Use the copy constructor to create a new instance from the original
    ArrayList copiedList(originalList);

    // Use the assignment operator to create another instance from the original
    ArrayList assignedList;
    assignedList = originalList;

    // Display the contents of the original, copied, and assigned lists
    cout << "Original List:" << std::endl;
    originalList.printALL();

    cout << "\nCopied List:" << std::endl;
    copiedList.printALL();

    cout << "\nAssigned List:" << std::endl;
    assignedList.printALL();
    
    originalList.removeAtId(2);
    cout << "Original List Size: " << originalList.getSize() << "\n";
    cout << "The capacity of Original List is: " << originalList.getCapacity() << endl;
    
    cout << "Original List:" << std::endl;
    originalList.printALL();

    cout << "\nCopied List:" << std::endl;
    copiedList.printALL();

    cout << "\nAssigned List:" << std::endl;
    assignedList.printALL();
    
    assignedList.reverseArray();
    cout << "\nReveresed Assigned List:" << std::endl;
    assignedList.printALL();
    
    assignedList.move(0,2);
    cout << "\nAfter Switching 0th and 2nd value Reveresed List:" << std::endl;
    assignedList.printALL();
    
    assignedList.move(0,4);

    return 0;
}
