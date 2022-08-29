#include "singly_linked_list.hpp"
#include <iostream>
#include <string>

void test_delete_tail() {
    std::cout << "----------------------------" << __func__ << "---------------------------\n";

    SinglyLinkedList<std::string> words;
    words.Append("foo");
    words.Append("bar");
    words.Append("bim");
    words.Append("baz");
    words.Append("quux");

    std::cout << "The origin list" << '\n';
    std::cout << "size: " << words.Count() << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';

    std::cout << "Delete the last item in the list" << '\n';
    words.Delete("quux");
    std::cout << "size: " << words.Count() << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';

    std::cout << "append another item" << '\n';
    words.Append("Quux");
    std::cout << "size: " << words.Count() << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';
}

int main()
{
    test_delete_tail();
    return 0;
}

