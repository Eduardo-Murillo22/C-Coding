#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new node with data in sorted order
    void insertSorted(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (!head) {
            newNode->prev = nullptr;
            head = tail = newNode;
        }
        else if (data <= head->data) {
            newNode->prev = nullptr;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (data >= tail->data) {
            newNode->prev = tail;
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
        else {
            Node* current = head;
            while (current->next && current->next->data < data) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next = newNode;
            newNode->next->prev = newNode;
        }
    }

    // Function to move a node to the front
    void prioritize(int data) {
        Node* current = head;
        while (current && current->data != data) {
            current = current->next;
        }

        if (current) {

            // Update the previous and next pointers
            current->prev->next = current->next;
            if (current->next) {
                current->next->prev = current->prev;
            }

            // Move the node to the front
            current->prev = nullptr;
            current->next = head;
            head->prev = current;
            head = current;
        }
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList sortedList;

    // Insert elements in sorted order
    sortedList.insertSorted(5);
    sortedList.insertSorted(2);
    sortedList.insertSorted(8);
    sortedList.insertSorted(3);
    sortedList.insertSorted(6);

    // Display the sorted linked list
    cout << "Sorted Linked List: ";
    sortedList.display();

    // Prioritize elements
    sortedList.prioritize(8);
    sortedList.prioritize(10);

    // Display the prioritized list
    cout << "Prioritized List: ";
    sortedList.display();

    return 0;
}
