#pragma once

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
};

// """ A singly-linked list. """
template <typename T>
class SinglyLinkedList {
public:

    // """ Create an empty list. """
    SinglyLinkedList(): head(nullptr), tail(nullptr), count(0) {
    }

    void Append(const T& data) {
        auto node = new Node(data);
        if (head != nullptr) {
            head->next
        } else {
        }
    }

private:
    Node* head;
    Node* tail;
    int count;
};
