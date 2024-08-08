#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

//template class definition for a singly linked list
template <typename T>
class LinkedList {
public:
    //constructor to initialize an empty linked list
    LinkedList();

    //destructor to clean up all nodes
    ~LinkedList();

    //add a new node with given data to the end of the list
    void add(const T& data);

    //remove the first occurrence of a node with the given data
    void remove(const T& data);

    //search for a node with the given data
    bool search(const T& data) const;

    //clear all nodes from the list
    void clear();

    //function to display the contents of the list
    void display() const;

    //node structure to represent each element in the linked list
    struct Node {
        T data;        
        Node* next;    
        Node(const T& data) : data(data), next(nullptr) {}
    };

    //getter for the head node of the list
    Node* getHead() const { return head; }

private:
    Node* head;  
    Node* tail;    

    //remove a node with the given data
    void remove(Node*& node, const T& data);
};

//template functions

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::add(const T& data) {
    Node* newNode = new Node(data);
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

template <typename T>
void LinkedList<T>::remove(const T& data) {
    remove(head, data);
}

template <typename T>
void LinkedList<T>::remove(Node*& node, const T& data) {
    if (node == nullptr) return;

    if (node->data == data) {
        Node* temp = node;
        node = node->next;
        delete temp;
        if (node == nullptr) {
            tail = nullptr;
        }
    }
    else {
        remove(node->next, data);
    }
}

template <typename T>
bool LinkedList<T>::search(const T& data) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

template <typename T>
void LinkedList<T>::display() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif // LINKEDLIST_H
