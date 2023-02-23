from doubly_linked_list import DoublyLinkedList

def test():
    dll = DoublyLinkedList()
    dll.Append("foo")
    dll.Append("bar")
    dll.Append("biz")
    dll.Append("whew")
    print("Items in List : ")
    dll.PrintFoward()
    print("List after deleting node with data whew")
    dll.Delete("whew")
    dll.PrintFoward()
    
    print("List count: {}".format(dll.count))
    print("Print list backwards")
    dll.PrintBackward()
    
    print("Reverse list ")
    dll.Reverse()
    dll.PrintFoward()
    
    print("Append item to front of list")
    dll.InsertHead(55)
    dll.PrintFoward()
    
    print("Get First element: {}".format(dll[0]))

if __name__ == "__main__":
    test()
