#pragma once

#include <stdexcept>
#include <iostream>

// """ A Doubly-linked lists' node. """
template <typename T>
struct Node {
    Node() {
        next = this;
        prev = this;
    }

    Node(const T& data): data(data) {
        next = this;
        prev = this;
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
    DoublyLinkedList(): count(0) {
        nil = &dummy;
    }

    ~DoublyLinkedList() {
        auto current = nil->next;
        while (current != nil) {
            auto node = current;
            current = current->next;
            delete node;
        }
    }

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    // """ Iterate through the list. """
    Iterator<T> begin() {
        return Iterator<T>(nil->next);
    }

    Iterator<T> end() {
        return Iterator<T>(nil);
    }
    
    // """ Iterate backwards through the list. """
    ReverseIterator<T> rbegin() {
        return ReverseIterator<T>(nil->prev);
    }

    ReverseIterator<T> rend() {
        return ReverseIterator<T>(nil);
    }

    // """ Append an item to the list. """
    void Append(const T& data) {
        auto node = new Node<T>(data);
        // insert before nil.
        auto current = nil;
        auto prev_node = current->prev;

        node->prev = prev_node;
        node->next = current;

        prev_node->next = node;
        current->prev = node;

        count += 1;
    }

    // """ Delete a node from the list. """
    bool Delete(const T& data) {
        auto current = nil->next;
        while (current != nil) {
            if (current->data == data) {
                auto prev_node = current->prev;
                auto succ_node = current->next;

                prev_node->next = succ_node;
                succ_node->prev = prev_node;

                delete current;
                count -= 1;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // """Search through the list. Return True if data is found, otherwise False."""
    bool Search(const T& data) {
        auto current = nil->next;
        while (current != nil) {
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
        // insert before nil->next.
        auto current = nil->next;
        auto prev_node = current->prev;

        node->prev = prev_node;
        node->next = current;

        prev_node->next = node;
        current->prev = node;
        
        count += 1;
    }

    T& operator[] (int index) {
        if (index > count - 1) {
            throw std::out_of_range("Index out of range.");
        }
        auto current = nil->next;    // Note subtle change
        for (int n = 0; n < index; n++) {
            current = current->next;
        }
        return current->data;
    }

    int Count() { return count; }

    // """ Reverse linked list. """
    void Reverse() {
        using std::swap;
        auto current = nil->next;
        while (current != nil) {
            swap(current->next, current->prev);
            current = current->prev;
        }

        // Now reverse the order of nil's next and prev 
        swap(nil->next, nil->prev);
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
    Node<T> dummy;
    Node<T>* nil;
    int count;
};

