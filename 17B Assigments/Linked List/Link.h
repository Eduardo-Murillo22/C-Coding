/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021 1:12pm
    Purpose: Linked list from first principles
*/

#ifndef LINK_H
#define LINK_H

#include <iostream>

class Link {
public:
    int data;      // Some type of data
    Link* lnkNext; // Next Link in the chain
};

class LinkedList {
private:
    Link* head; // Pointer to the first link

public:
    Link* create(int data) {
        Link* link = new Link;
        link->data = data;
        link->lnkNext = nullptr;
        return link;
    }

    void pshFrnt(Link*& front, Link* newLink) {
        newLink->lnkNext = front;
        front = newLink;
    }

    void pshBack(Link*& front, Link* newLink) {
        if (front == nullptr) {
            front = newLink;
            return;
        }

        Link* temp = front;
        while (temp->lnkNext != nullptr) {
            temp = temp->lnkNext;
        }
        temp->lnkNext = newLink;
    }

    Link* popFrnt(Link*& front) {
        if (front == nullptr) {
            std::cout << "The list is empty. Cannot pop from an empty list." << std::endl;
            return nullptr;
        }

        Link* temp = front;
        front = front->lnkNext;
        temp->lnkNext = nullptr;

        return temp;
    }

    Link* popBack(Link*& front) {
        if (front == nullptr)
            return nullptr;

        Link* temp = front;
        Link* prev = nullptr;
        while (temp->lnkNext != nullptr) {
            prev = temp;
            temp = temp->lnkNext;
        }

        if (prev != nullptr) {
            prev->lnkNext = nullptr;
            return temp;
        } else {
            delete temp;
            return nullptr;
        }
    }

    Link* fillLst(int n) {
        head = nullptr;

        for (int i = n; i >= 1; --i) {
            Link* newLink = create(i);
            pshFrnt(head, newLink);
        }

        return head;
    }

    void prntLst(Link* next) {
        while (next != nullptr) {
            std::cout << next->data << std::endl;
            next = next->lnkNext;
        }
    }

    void destroy(Link* front) {
        while (front != nullptr) {
            Link* temp = front;
            front = front->lnkNext;
            delete temp;
        }
    }
};

#endif /* LINK_H */
