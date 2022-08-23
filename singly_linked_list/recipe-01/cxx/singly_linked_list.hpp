#pragma once

#include <stdexcept>

// """ A singly-linked node. """
template <typename T>
struct Node {
    Node(const T& data): next(nullptr), data(data) {
    }

    Node* next;
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
        return !(*this == other);
    }

    Node<T>* current;
};

// """ A singly-linked list. """
template <typename T>
class SinglyLinkedList {
public:
    // """ Create an empty list. """
    SinglyLinkedList(): head(nullptr), tail(nullptr), count(0) {
    }

    ~SinglyLinkedList() {
        auto current = head;
        while (current) {
            auto node = current;
            current = current->next;
            delete node;
        }
    }

    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete; 

    // """ Iterate through the list. """
    Iterator<T> begin() {
        return Iterator<T>(head);
    }

    Iterator<T> end() {
        return Iterator<T>(nullptr);
    }

    // """ Append an item to the list """
    void Append(const T& data) {
        auto node = new Node<T>(data);
        if (tail) {
            tail->next = node;
            tail = node;
        } else {
            head = node;
            tail = node;
        }
        count += 1;
    }

    // """ Delete a node from the list """
    void Delete(const T& data) {
        auto current = head;
        auto prev = head;
        while (current) {
            if (current->data == data) {
                if (current == head) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                count -= 1;
            } else {
                prev = current;
            }
            current = prev->next;
        }
    }

    // """ Search through the list. Return True if data is found, otherwise
    // False. """
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

    T& operator[](int index) {
        if (index > count - 1) {
            throw std::out_of_range("Index out of range.");
        }
        auto current = head;
        for (int n = 0; n < index; n++) {
            current = current->next;
        }
        return current->data;
    }

    int Count() { return count; }

    // """ Reverse the links of the list """
    void Reverse() {
        Node<T>* next;
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        swap(head, tail);
    }

    // """ Sort the list """
    void Sort() {
        SinglyLinkedList output_list;
        auto current = head;
        while (current) {
            auto next = current->next;

            // """ insert the node into output_list and keep sorted """
            auto output_current = output_list.head;
            auto output_prev = output_list.head;
            while (output_current) {
                if (current->data < output_current->data)
                    break;
                output_prev = output_current;
                output_current = output_current->next;
            }
            current->next = output_current;
            if (output_current == output_list.head) {
                output_list.head = current;
            } else {
                output_prev->next = current;
            }
            if (current->next == nullptr) {
                output_list.tail = current;
            }

            current = next;
        }

        head = output_list.head;
        tail = output_list.tail;

        output_list.head = nullptr;
        output_list.tail = nullptr;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    int count;
};
