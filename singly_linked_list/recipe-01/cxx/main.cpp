#include "singly_linked_list.hpp"
#include <string>
#include <iostream>

void test()
{
    std::cout << "----------------------------" << __func__ << "---------------------------\n";

    SinglyLinkedList<std::string> words;
    words.Append("foo");
    words.Append("bar");
    words.Append("bim");
    words.Append("baz");
    words.Append("quux");

    std::cout << "access by index" << '\n';
    std::cout << "here is a node: " << words[1] << '\n';

    std::cout << "modify by index" << '\n';
    words[4] = "Quux";
    std::cout << "Modified node by index: " << words[4] << '\n';

    std::cout << "This list has " << words.Count() << " elements." << '\n';
    for (const auto& word : words)
        std::cout << "Got this data: " << word << '\n';
    
    if (words.Search("foo"))
        std::cout << "Found foo in the list." << '\n';
    if (words.Search("amiga"))
        std::cout << "Found amiga in the list." << '\n';
    
    std::cout << "Now we try to Delete an item" << '\n';
    words.Delete("bim");
    std::cout << "List now has " << words.Count() << " elements" << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';

    std::cout << "Delete the first item in the list" << '\n';
    words.Delete("foo");
    std::cout << "size: " << words.Count() << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';
    
    std::cout << "Delete the last item in the list" << '\n';
    words.Delete("quux");
    std::cout << "size: " << words.Count() << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';
}

void test_reverse()
{
    std::cout << "----------------------------" << __func__ << "---------------------------\n";

    SinglyLinkedList<std::string> words;
    words.Append("foo");
    words.Append("bar");
    words.Append("bim");
    words.Append("baz");
    words.Append("quux");

    std::cout << "The origin list" << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';

    std::cout << "Reverse the list" << '\n';
    words.Reverse();
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';
}

int main()
{
    test();
    test_reverse();
    return 0;
}

