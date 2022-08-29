from singly_linked_list import SinglyLinkedList

def test_delete_tail():
    print("----------------------------test_delete_tail---------------------------");

    numbers = SinglyLinkedList()
    for i in range(5):
        numbers.Append(i)
    
    print("The origin list");
    for number in numbers:
        print("data: {}".format(number))

    print("Delete the last item in the list")
    numbers.Delete(4)
    print("size: {}".format(numbers.count))
    for number in numbers:
        print("data: {}".format(number))

    print("append another item")
    numbers.Append(6)
    print("size: {}".format(numbers.count))
    for number in numbers:
        print("data: {}".format(number))

def main():
    test_delete_tail()

main()
