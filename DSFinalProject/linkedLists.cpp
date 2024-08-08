/*#include "linkedLists.h"

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
*/