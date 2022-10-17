#include "doubly_linked_list.hpp"

#include <string>

void test() {
    DoublyLinkedList<std::string> dll;
    dll.Append("foo");
    dll.Append("bar");
    dll.Append("biz");
    dll.Append("whew");

    std::cout << "Items in List : " << '\n';
    dll.PrintFoward();

    std::cout << "List after deleting node with data whew" << '\n';
    dll.Delete("whew");
    dll.PrintFoward();

    std::cout << "List count: " << dll.Count() << '\n';
    std::cout << "Print list backwards" << '\n';
    dll.PrintBackward();

    std::cout << "Reverse list " << '\n';
    dll.Reverse();
    dll.PrintFoward();

    std::cout << "Append item to front of list" << '\n';
    dll.InsertHead(std::to_string(55));
    dll.PrintFoward();

    std::cout << "Get First element: " << dll[0] << '\n';
}

int main()
{
    test();
    return 0;
}
