from singly_linked_list import SinglyLinkedList

def test():
    print("----------------------------test---------------------------");

    words = SinglyLinkedList()
    words.Append(627)
    words.Append(758)
    words.Append(113)
    words.Append(101)
    words.Append(515)
    
    print("access by index")
    print("here is a node: {}".format(words[1]))
    
    print("modify by index")
    words[4] = 1515
    print("Modified node by index: {}".format(words[4]))
    
    print("This list has {} elements.".format(words.count))
    for word in words:
        print("Got this data: {}".format(word))
    
    if words.Search(627):
        print("Found 627 in the list.")
    if words.Search(838):
        print("Found 838 in the list.")
    
    print("Now we try to Delete an item")
    words.Delete(113)
    print("List now has {} elements".format(words.count))
    for word in words:
        print("data: {}".format(word))
    
    print("Delete the first item in the list")
    words.Delete(627)
    print("size: {}".format(words.count))
    for word in words:
        print("data: {}".format(word))
    
    print("Delete the last item in the list")
    words.Delete(515)
    print("size: {}".format(words.count))
    for word in words:
        print("data: {}".format(word))

def test_reverse():
    print("----------------------------test_reverse---------------------------");

    words = SinglyLinkedList()
    words.Append(627)
    words.Append(758)
    words.Append(113)
    words.Append(101)
    words.Append(515)
    
    print("The origin list");
    for word in words:
        print("data: {}".format(word))

    print("Reverse the list");
    words.Reverse();
    for word in words:
        print("data: {}".format(word))

def test_sort():
    print("----------------------------test_sort---------------------------");

    words = SinglyLinkedList()
    words.Append(627)
    words.Append(758)
    words.Append(113)
    words.Append(101)
    words.Append(515)
    
    print("The origin list");
    for word in words:
        print("data: {}".format(word))

    print("Sort the list");
    words.Sort();
    for word in words:
        print("data: {}".format(word))

def main():
    test()
    test_reverse()
    test_sort()

main()
