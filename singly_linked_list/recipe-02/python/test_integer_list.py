from singly_linked_list import SinglyLinkedList

def test():
    numbers = SinglyLinkedList()
    numbers.Append(627)
    numbers.Append(758)
    numbers.Append(113)
    numbers.Append(101)
    numbers.Append(515)
    
    print("access by index")
    print("here is a node: {}".format(numbers[1]))
    
    print("modify by index")
    numbers[4] = 1515
    print("Modified node by index: {}".format(numbers[4]))
    
    print("This list has {} elements.".format(numbers.count))
    for number in numbers:
        print("data: {}".format(number))
    
    if numbers.Search(627):
        print("Found 627 in the list.")
    if numbers.Search(838):
        print("Found 838 in the list.")
    
    print("Now we try to Delete an item")
    numbers.Delete(113)
    print("List now has {} elements".format(numbers.count))
    for number in numbers:
        print("data: {}".format(number))
    
    print("Delete the first item in the list")
    numbers.Delete(627)
    print("size: {}".format(numbers.count))
    for number in numbers:
        print("data: {}".format(number))
    
    print("Delete the last item in the list")
    numbers.Delete(1515)
    print("size: {}".format(numbers.count))
    for number in numbers:
        print("data: {}".format(number))

if __name__ == "__main__":
    test()
