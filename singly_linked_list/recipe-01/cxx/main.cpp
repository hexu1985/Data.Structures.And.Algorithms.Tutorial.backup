#include "singly_linked_list.hpp"
#include <string>
#include <iostream>

int main()
{
    SinglyLinkedList<std::string> words;
    words.Append("foo");
    words.Append("bar");
    words.Append("bim");
    words.Append("baz");
    words.Append("quux");

    std::cout << "access by index" << "\n";
    std::cout << "here is a node: " << words[1] << "\n";

    return 0;
}

