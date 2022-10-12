from singly_linked_list import SinglyLinkedList

N = 10

def test():
    numbers = SinglyLinkedList()
    for i in range(2, N+1):
        numbers.Append(i)

    for number in numbers:
        print(number, end=" ")
    print()

    numbers.Reverse();

    for number in numbers:
        print(number, end=" ")
    print()

if __name__ == "__main__":
    test()
