#include "singly_linked_list.hpp"
#include <iostream>

void test()
{
    std::cout << "----------------------------" << __func__ << "---------------------------\n";

    SinglyLinkedList<int> words;
    words.Append(627);
    words.Append(758);
    words.Append(113);
    words.Append(101);
    words.Append(515);

    std::cout << "access by index" << '\n';
    std::cout << "here is a node: " << words[1] << '\n';

    std::cout << "modify by index" << '\n';
    words[4] = 1515;
    std::cout << "Modified node by index: " << words[4] << '\n';

    std::cout << "This list has " << words.Count() << " elements." << '\n';
    for (const auto& word : words)
        std::cout << "Got this data: " << word << '\n';
    
    if (words.Search(627))
        std::cout << "Found 627 in the list." << '\n';
    if (words.Search(838))
        std::cout << "Found 838 in the list." << '\n';
    
    std::cout << "Now we try to Delete an item" << '\n';
    words.Delete(113);
    std::cout << "List now has " << words.Count() << " elements" << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';

    std::cout << "Delete the first item in the list" << '\n';
    words.Delete(627);
    std::cout << "size: " << words.Count() << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';
    
    std::cout << "Delete the last item in the list" << '\n';
    words.Delete(515);
    std::cout << "size: " << words.Count() << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';
}

void test_reverse()
{
    std::cout << "----------------------------" << __func__ << "---------------------------\n";

    SinglyLinkedList<int> words;
    words.Append(627);
    words.Append(758);
    words.Append(113);
    words.Append(101);
    words.Append(515);

    std::cout << "The origin list" << '\n';
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';

    std::cout << "Reverse the list" << '\n';
    words.Reverse();
    for (const auto& word : words)
        std::cout << "data: " << word << '\n';
}

void test_sort()
{
    std::cout << "----------------------------" << __func__ << "---------------------------\n";

    SinglyLinkedList<int> words;
    words.Append(627);
    words.Append(758);
    words.Append(113);
    words.Append(101);
    words.Append(515);

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
    test_reverse();
    test_sort();
    return 0;
}

