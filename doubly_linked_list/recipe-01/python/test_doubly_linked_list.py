from doubly_linked_list import DoublyLinkedList

def test():
    dll = DoublyLinkedList()
    dll.append("foo")
    dll.append("bar")
    dll.append("biz")
    dll.append("whew")
    print("Items in List : ")
    dll.print_foward()
    print("List after deleting node with data whew")
    dll.delete("whew")
    dll.print_foward()
    
    print("List count: {}".format(dll.count))
    print("Print list backwards")
    dll.print_backward()
    
    print("Reverse list ")
    dll.reverse()
    dll.print_foward()
    
    print("Append item to front of list")
    dll.insert_head(55)
    dll.print_foward()
    
    print("Get First element: {}".format(dll[0]))

if __name__ == "__main__":
    test()
