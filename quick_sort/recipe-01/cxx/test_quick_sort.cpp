// sort algorithm example
#include <iostream>     // std::cout
#include <vector>       // std::vector

#include "quick_sort.hpp"

int main () 
{
    std::vector<int> myvector = {32,71,12,45,26,80,53,33};  // 32 71 12 45 26 80 53 33

    // using object as comp
    QuickSort(myvector);                                    //(12 26 32 33 45 53 71 80)

    // print out content:
    std::cout << "myvector contains:";
    for (const auto& item: myvector)
        std::cout << ' ' << item;
    std::cout << '\n';

    return 0;
}

/*
Output:
myvector contains: 12 26 32 33 45 53 71 80
*/
