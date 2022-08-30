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

    print("Reverse the list");
    words.Reverse();
    for word in words:
        print("data: {}".format(word))

if __name__ == "__main__":
    test()
