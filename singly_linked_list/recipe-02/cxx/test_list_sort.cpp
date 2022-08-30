#include "singly_linked_list.hpp"
#include <string>
#include <iostream>

void test() {
    SinglyLinkedList<std::string> words;
    words.Append("foo");
    words.Append("bar");
    words.Append("bim");
    words.Append("baz");
    words.Append("quux");

    std::cout << "The origin list" << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';

    std::cout << "Sort the list" << '\n';
    words.Sort();
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';
}

int main()
{
    test();
    return 0;
}

