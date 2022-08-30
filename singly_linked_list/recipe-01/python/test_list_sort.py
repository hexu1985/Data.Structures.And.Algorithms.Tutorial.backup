from singly_linked_list import SinglyLinkedList

def test():
    words = SinglyLinkedList()
    words.Append('foo')
    words.Append('bar')
    words.Append('bim')
    words.Append('baz')
    words.Append('quux')
    
    print("The origin list");
    for word in words:
        print("data: {}".format(word))

    print("Sort the list");
    words.Sort();
    for word in words:
        print("data: {}".format(word))

if __name__ == "__main__":
    test()
