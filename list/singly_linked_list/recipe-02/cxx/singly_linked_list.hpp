#pragma once

#include <stdexcept>

// """ A singly-linked node. """
template <typename T>
struct Node {
    Node(): next(nullptr) {
    }

    Node(const T& data): next(nullptr), data(data) {
    }

    Node* next;
    T data;
};

template <typename T>
struct Iterator {
    Iterator(Node<T>* node): current(node) {
    }

    T& operator*() { return current->data; }

    T* operator->() { return &current->data; }

    Iterator& operator++() {
        current = current->next;
        return *this;
    }

    Iterator operator++(int) {
        Iterator tmp(*this);
        current = current->next;
        return tmp;
    }

    bool operator==(const Iterator& other) const {   
        return (this->current == other.current);
    }

    bool operator!=(const Iterator& other) const {
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
        head = &dummy;
        head->next = nullptr;
        tail = head;
    }

    ~SinglyLinkedList() {
        auto current = head->next;
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
        return Iterator<T>(head->next);
    }

    Iterator<T> end() {
        return Iterator<T>(nullptr);
    }

    // """ Append an item to the list """
    void Append(const T& data) {
        auto node = new Node<T>(data);
        tail->next = node;
        tail = node;
        count += 1;
    }

    // """ Delete a node from the list """
    bool Delete(const T& data) {
        auto current = head->next;
        auto prev = head;
        while (current) {
            if (current->data == data) {
                prev->next = current->next;
                if (current == tail) {
                    tail = prev;
                }
                delete current;
                count -= 1;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    // """ Search through the list. Return True if data is found, otherwise
    // False. """
    bool Search(const T& data) {
        auto current = head->next;
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    T& operator[] (int index) {
        if (index > count - 1) {
            throw std::out_of_range("Index out of range.");
        }
        auto current = head->next;
        for (int n = 0; n < index; n++) {
            current = current->next;
        }
        return current->data;
    }

    int Count() { return count; }

    // """ Reverse the links of the list """
    void Reverse() {
        auto current = head->next;  // 指向头Node: current可能为空
        head->next = nullptr;               // 重置list头
        tail = current ? current : head;    // 记录list尾
        while (current) {           // 遍历list
            auto next = current->next;

            // 在list表头插入Node
            current->next = head->next;
            head->next = current;

            current = next;
        }
    }

    // """ Sort the list """
    void Sort() {
        auto current = head->next;  // 指向头Node: current可能为空
        head->next = nullptr;       // 重置list头
        tail = head;                // 重置list尾

        while (current) {           // 遍历list
            auto next = current->next;

            // insert the node into output_list and keep sorted
            auto output_current = head->next;
            auto output_prev = head;
            while (output_current) {
                if (current->data < output_current->data)
                    break;
                output_prev = output_current;
                output_current = output_current->next;
            }
            current->next = output_current;
            output_prev->next = current;
            if (current->next == nullptr) { // 更新list尾
                tail = current;
            }

            current = next;
        }
    }

private:
    Node<T> dummy;
    Node<T>* head;
    Node<T>* tail;
    int count;
};
