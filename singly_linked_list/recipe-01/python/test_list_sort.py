import random

from singly_linked_list import SinglyLinkedList

N = 10

def test():
    numbers = SinglyLinkedList()
    for i in range(0, N-1):
        numbers.Append(random.randint(0,999))

    for number in numbers:
        print(number, end=" ")
    print()

    numbers.Sort();

    for number in numbers:
        print(number, end=" ")
    print()

if __name__ == "__main__":
    test()
