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
    Iterator(Node<T>* node): current(node) {
    }

    T& operator* ()
    {
        assert(current != nullptr);
        return current->data;
    }

    T* operator-> ()
    {
        assert(current != nullptr);
        return &current->data;
    }

    Iterator& operator++ ()
    {
        next();
        return *this;
    }

    Iterator operator++ (int)
    {
        Iterator tmp(*this);
        next();
        return tmp;
    }

    bool operator== (const Iterator& other) const
    {   
        return (this->current == other.current);
    }

    bool operator!= (const Iterator& other) const
    {
        return !(*this == other);
    }

    void next()
    {
        assert(current != nullptr);
        current = current->next;
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

    // """ Iterate through the list. """
    Iterator<T> begin() {
        return Iterator<T>(head);
    }

    Iterator<T> end() {
        return Iterator<T>(nullptr);
    }

    // """ Append an item to the list """
    void Append(const T& data) {
        auto node = new Node(data);
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
    void Search(const T& data) {
        auto current = head;
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false
    }

    T& operator[](int index) {
        if (index > count - 1) {
            throw std::out_of_range("Index out of range.")
        }
        auto current = head;
        for (int n = 0; n < index; n++) {
            current = current->next;
        }
        return current->data;
    }

private:
    Node* head;
    Node* tail;
    int count;
};
