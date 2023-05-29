#include "singly_linked_list.hpp"
#include <string>
#include <iostream>

const int N = 10;

void test() {
    SinglyLinkedList<int> numbers;
    for (int i = 2; i < N+1; i++) {
        numbers.Append(i);
    }

    for (auto number : numbers) std::cout << number << ' ';
    std::cout << std::endl;

    numbers.Reverse();

    for (auto number : numbers) std::cout << number << ' ';
    std::cout << std::endl;
}

int main()
{
    test();
    return 0;
}


