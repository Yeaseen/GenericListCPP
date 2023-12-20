/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
        clear();
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

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            addToFreeList(temp);
        }
        currentSize = 0;
    }

    void addToFreeList(Node* node) {
        // Add the node to the free list
        node->next = freeList;
        freeList = node;
    }
};



int main(){


  cout<<"Hello LL!"<<endl;
  ArrayList myList;

    myList.add(42);
    myList.add("Hello");
    myList.add(3.14f);

    cout << "List Size: " << myList.getSize() << endl;

    myList.printALL();

    // Remove the 2nd item (index 1)
    myList.removeAt(1);

    cout << "List Size after removal: " << myList.getSize() << endl;



  return 0;
}
