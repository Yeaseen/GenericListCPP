#include <iostream>
#include <sstream>
#include <cstdlib>
#include <variant>
#include <string>

using namespace std;

using MultiType = variant<int, string, float, double>;

class Node {
public:
    MultiType data;
    Node* next;

    Node(const MultiType& element) : data(element), next(nullptr) {}
};

class ArrayList {
private:
    Node* head;
    int currentSize;
    Node* freeList; // New: to keep track of freed nodes

public:
    ArrayList() : head(nullptr), currentSize(0), freeList(nullptr) {}

    ~ArrayList() {
      clearLists();
    }
    
    // Copy Constructor
    ArrayList(const ArrayList& other) : head(nullptr), currentSize(0), freeList(nullptr) {
    // Copy elements from the other list to this list
    Node* currentOther = other.head;
    while (currentOther) {
        add(currentOther->data);
        currentOther = currentOther->next;
    }
}

// Assignment Operator
ArrayList& operator=(const ArrayList& other) {
    if (this != &other) {
        // Clear existing data in this list
        clear();

        // Copy elements from the other list to this list
        Node* currentOther = other.head;
        while (currentOther) {
            add(currentOther->data);
            currentOther = currentOther->next;
        }
    }
    return *this;
}

    void add(const MultiType& element) {
        Node* newNode = getFreeNode();
        if (!newNode) {
            newNode = new Node(element);
        } else {
            newNode->data = element;
        }
        newNode->next = head;
        head = newNode;
        ++currentSize;
    }

    void removeAt(int index) {
        if (index < 0 || index >= currentSize) {
            cout << "Invalid index for removal." << endl;
        return; // Invalid index
        }

        Node* toRemove = getNodeAtIndex(index);
        if (toRemove) {
            // Add the removed node to the free list
            toRemove->next = freeList;
            freeList = toRemove;
            --currentSize;
        }
    }

    const MultiType* gets(int index) const {
        Node* current = getNodeAtIndex(index);
        return (current) ? &(current->data) : nullptr;
    }

    int getSize() const {
        return currentSize;
    }
    
    
    
    void printAvalue(int id) const {
        const MultiType* element = this->gets(id);
        if (element) {
            cout << "Element " << id << ": ";
            if (holds_alternative<int>(*element)) {
                cout << get<int>(*element);
            } else if (holds_alternative<string>(*element)) {
                cout << get<string>(*element);
            } else if (holds_alternative<float>(*element)) {
                cout << get<float>(*element);
            } else if (holds_alternative<double>(*element)) {
                cout << get<double>(*element);
            }
            cout << endl;
        }
    }

   void printALL() const{

    cout << endl;
    for(int i=0; i<currentSize; i++){
        printAvalue(i);
        
    }
    }
    void reverseList(){
      Node* prev=nullptr;
      while(head != nullptr){
          Node* nxt = head->next;
          head->next = prev;
          prev = head;
          head = nxt;
      }

      head = prev;

    }
    
   void concat(const ArrayList& second) {
    Node* secondHead = second.head;
    if (!secondHead) return;
    
    if (!head) {
        // If the first list is empty, simply update the head to the head of the second list
        head = secondHead;
        currentSize = second.currentSize;
        return;
    }

    
    Node* track = head;
    while (track->next) {
        track = track->next;
    }
    track->next = secondHead;
    currentSize += second.currentSize;
}

private:
    Node* getNodeAtIndex(int index) const {
        Node* current = head;
        for (int i = 0; i < index && current; ++i) {
            current = current->next;
        }
        return current;
    }

    Node* getFreeNode() {
        if (freeList) {
            Node* freeNode = freeList;
            freeList = freeNode->next;
            return freeNode;
        }
        return nullptr;
    }

    void addToFreeList(Node* node) {
        // Add the node to the free list
        node->next = freeList;
        freeList = node;
    }
    
    
    
  void clearLists() {
        // Clear linked list
        while (head) {
            Node* temp = head;
            head = head->next;
            addToFreeList(temp);
        }

        // Clear free list
        while (freeList) {
            Node* temp = freeList;
            freeList = freeList->next;
            delete temp;
        }
    }
    void clear() {
        clearLists();
        currentSize = 0;
    }
};



int main(){


  
    ArrayList myList;

    myList.add(56);
    myList.add("My Boy");
    myList.add(2.79f);

    cout << "List Size: " << myList.getSize() << endl;

    myList.printALL();

    // Remove the 2nd item (index 1)
    myList.removeAt(1);

    cout << "List Size after removal: " << myList.getSize() << endl;

    // Reverse the list
    myList.reverseList();

    cout << "Reversed List:" << endl;
    myList.printALL();
    
    
     // Create the original list
    ArrayList originalList;
    originalList.add(42);
    originalList.add("Hello");
    originalList.add(3.14f);

    cout << "Original List:" << endl;
    originalList.printALL();

    // Test copy constructor
    ArrayList copiedList = originalList;
    cout << "Copied List:" << endl;
    copiedList.printALL();

    // Test assignment operator
    ArrayList assignedList;
    assignedList = originalList;
    cout << "Assigned List:" << endl;
    assignedList.printALL();
    
    assignedList.concat(myList);
    cout << "Concated Assigned List with Original List:" << endl;
    assignedList.printALL();

  return 0;
}
