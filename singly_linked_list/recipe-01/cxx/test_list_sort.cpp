#include "singly_linked_list.hpp"
#include <string>
#include <iostream>
#include <random>

const int N = 10;

void test() {
    SinglyLinkedList<int> numbers;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 999);
    for (int i = 0; i < N-1; i++) {
        numbers.Append(distribution(generator));
    }

    for (auto number : numbers) std::cout << number << ' ';
    std::cout << std::endl;

    numbers.Sort();

    for (auto number : numbers) std::cout << number << ' ';
    std::cout << std::endl;
}

int main()
{
    test();
    return 0;
}


