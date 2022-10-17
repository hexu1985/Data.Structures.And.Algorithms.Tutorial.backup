#pragma once

#include <stdexcept>
#include <iostream>

// """ A Doubly-linked lists' node. """
template <typename T>
struct Node {
    Node(const T& data): next(nullptr), prev(nullptr), data(data) {
    }

    Node* next;
    Node* prev;
    T data;
};

template <typename T>
struct Iterator {
    Iterator(Node<T>* node): current(node) {
    }

    T& operator* () { return current->data; }

    T* operator-> () { return &current->data; }

    Iterator& operator++ () {
        current = current->next;
        return *this;
    }

    Iterator operator++ (int) {
        Iterator tmp(*this);
        current = current->next;
        return tmp;
    }

    bool operator== (const Iterator& other) const {
        return (this->current == other.current);
    }

    bool operator!= (const Iterator& other) const {
        return (this->current != other.current);
    }

    Node<T>* current;
};

template <typename T>
struct ReverseIterator {
    ReverseIterator(Node<T>* node): current(node) {
    }

    T& operator* () { return current->data; }

    T* operator-> () { return &current->data; }

    ReverseIterator& operator++ () {
        current = current->prev;
        return *this;
    }

    ReverseIterator operator++ (int) {
        ReverseIterator tmp(*this);
        current = current->prev;
        return tmp;
    }

    bool operator== (const ReverseIterator& other) const {
        return (this->current == other.current);
    }

    bool operator!= (const ReverseIterator& other) const {
        return (this->current != other.current);
    }

    Node<T>* current;
};

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList(): head(nullptr), tail(nullptr), count(0) {
    }

    ~DoublyLinkedList() {
        auto current = head;
        while (current) {
            auto node = current;
            current = current->next;
            delete node;
        }
    }

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    // """ Iterate through the list. """
    Iterator<T> begin() {
        return Iterator<T>(head);
    }

    Iterator<T> end() {
        return Iterator<T>(nullptr);
    }
    
    // """ Iterate backwards through the list. """
    ReverseIterator<T> rbegin() {
        return ReverseIterator<T>(tail);
    }

    ReverseIterator<T> rend() {
        return ReverseIterator<T>(nullptr);
    }

    // """ Append an item to the list. """
    void Append(const T& data) {
        auto node = new Node<T>(data);
        if (head) { // list not empty
            node->prev = tail;
            tail->next = node;
            tail = node;
        } else {
            tail = head = node;
        }
        count += 1;
    }

    // """ Delete a node from the list. """
    void Delete(const T& data) {
        auto current = head;
        while (current) {
            if (current->data == data) {
                if (current == head) {
                    head = current->next;
                    if (head) {
                        head->prev = nullptr;
                    }
                } else {
                    current->prev->next = current->next;
                }
                if (current == tail) {
                    tail = current->prev;
                    if (tail) {
                        tail->next = nullptr;
                    }
                } else {
                    current->next->prev = current->prev;
                }
                delete current;
                count -= 1;
                return;
            }
            current = current->next;
        }
    }

    // """Search through the list. Return True if data is found, otherwise False."""
    bool Search(const T& data) {
        auto current = head;
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // """ Insert new node at the head of linked list. """
    void InsertHead(const T& data) {
        auto node = new Node<T>(data);
        if (head) { // list not empty
            head->prev = node;
            node->next = head;
            head = node;
        } else {
            tail = head = node;
        }
        count += 1;
    }

    T& operator[] (int index) {
        if (index > count - 1) {
            throw std::out_of_range("Index out of range.");
        }
        auto current = head;    // Note subtle change
        for (int n = 0; n < index; n++) {
            current = current->next;
        }
        return current->data;
    }

    int Count() { return count; }

    // """ Reverse linked list. """
    void Reverse() {
        using std::swap;
        auto current = head;
        while (current) {
            swap(current->next, current->prev);
            current = current->prev;
        }

        // Now reverse the order of head and tail
        swap(head, tail);
    }

    void PrintFoward() {
        auto first = begin();
        auto last = end();
        while (first != last) {
            std::cout << *first << '\n';
            ++first;
        }
    }

    void PrintBackward() {
        auto first = rbegin();
        auto last = rend();
        while (first != last) {
            std::cout << *first << '\n';
            ++first;
        }
    }

private:
    Node<T>* head;
    Node<T>* tail;
    int count;
};

