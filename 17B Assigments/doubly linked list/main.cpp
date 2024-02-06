/* 
 * File:   main.cpp
 * Author: Eduardo Murillo
 *
 * Created on October 24, 2023, 11:13 PM
 */

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class LinkedList {
private:
    Node* head; // Mark the start
    Node* tail; // Mark the end

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert(int data) {
        Node* n = new Node;
        n->data = data;
        n->next = NULL;

        if (head == NULL) {
            n->prev = NULL;
            head = n;
            tail = n;
        } else if (data <= head->data) {
            n->next = head;
            n->prev = NULL;
            head->prev = n;
            head = n;
        } else if (data >= tail->data) {
            n->next = NULL;
            n->prev = tail;
            tail->next = n;
            tail = n;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->data < data) {
                temp = temp->next;
            }
            n->next = temp->next;
            n->prev = temp;
            temp->next = n;
            n->next->prev = n;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void prio(int data) {
        Node* temp = head;

        while (temp != NULL) {
            if (data == temp->data) {
                if (temp == head) {
                    return; // Node is already at the front
                }

                // Update the previous and next pointers of the adjacent nodes
                if (temp->prev) {
                    temp->prev->next = temp->next;
                }
                if (temp->next) {
                    temp->next->prev = temp->prev;
                }

                // Move the node to the front
                temp->prev = NULL;
                temp->next = head;
                head->prev = temp;
                head = temp;

                return; // We found and moved the node, no need to continue searching
            }

            temp = temp->next; // Move to the next node
        }
    }

};

int main(int argc, char** argv) {
    LinkedList n;

    n.insert(3);
    n.insert(5);
    n.insert(2);
    n.insert(34);
    n.insert(8);
    n.insert(22);
    n.insert(33);
    n.insert(54);
    n.insert(21);
    n.insert(14);
    n.insert(18);
    n.insert(32);
    
    cout << "Prioritized number 22,21,8 to be in the front" << endl;
    n.prio(22);
    n.prio(21);
    n.prio(8);

    n.print();

    return 0;
}
