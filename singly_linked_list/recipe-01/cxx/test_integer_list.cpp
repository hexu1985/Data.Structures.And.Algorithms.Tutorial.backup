#include "singly_linked_list.hpp"
#include <iostream>

void test()
{
    std::cout << "----------------------------" << __func__ << "---------------------------\n";

    SinglyLinkedList<int> numbers;
    numbers.Append(627);
    numbers.Append(758);
    numbers.Append(113);
    numbers.Append(101);
    numbers.Append(515);

    std::cout << "access by index" << '\n';
    std::cout << "here is a node: " << numbers[1] << '\n';

    std::cout << "modify by index" << '\n';
    numbers[4] = 1515;
    std::cout << "Modified node by index: " << numbers[4] << '\n';

    std::cout << "This list has " << numbers.Count() << " elements." << '\n';
    for (const auto& number : numbers)
        std::cout << "Got this data: " << number << '\n';
    
    if (numbers.Search(627))
        std::cout << "Found 627 in the list." << '\n';
    if (numbers.Search(838))
        std::cout << "Found 838 in the list." << '\n';
    
    std::cout << "Now we try to Delete an item" << '\n';
    numbers.Delete(113);
    std::cout << "List now has " << numbers.Count() << " elements" << '\n';
    for (const auto& number : numbers)
        std::cout << "data: " << number << '\n';

    std::cout << "Delete the first item in the list" << '\n';
    numbers.Delete(627);
    std::cout << "size: " << numbers.Count() << '\n';
    for (const auto& number : numbers)
        std::cout << "data: " << number << '\n';
    
    std::cout << "Delete the last item in the list" << '\n';
    numbers.Delete(515);
    std::cout << "size: " << numbers.Count() << '\n';
    for (const auto& number : numbers)
        std::cout << "data: " << number << '\n';
}

void test_reverse()
{
    std::cout << "----------------------------" << __func__ << "---------------------------\n";

    SinglyLinkedList<int> numbers;
    numbers.Append(627);
    numbers.Append(758);
    numbers.Append(113);
    numbers.Append(101);
    numbers.Append(515);

    std::cout << "The origin list" << '\n';
    for (const auto& number : numbers)
        std::cout << "data: " << number << '\n';

    std::cout << "Reverse the list" << '\n';
    numbers.Reverse();
    for (const auto& number : numbers)
        std::cout << "data: " << number << '\n';
}

void test_sort()
{
    std::cout << "----------------------------" << __func__ << "---------------------------\n";

    SinglyLinkedList<int> numbers;
    numbers.Append(627);
    numbers.Append(758);
    numbers.Append(113);
    numbers.Append(101);
    numbers.Append(515);

    std::cout << "The origin list" << '\n';
    for (const auto& number : numbers)
        std::cout << "data: " << number << '\n';

    std::cout << "Sort the list" << '\n';
    numbers.Sort();
    for (const auto& number : numbers)
        std::cout << "data: " << number << '\n';
}

int main()
{
    test();
    test_reverse();
    test_sort();
    return 0;
}

