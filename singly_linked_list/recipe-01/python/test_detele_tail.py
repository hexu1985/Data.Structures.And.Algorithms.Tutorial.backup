from singly_linked_list import SinglyLinkedList

def test_delete_tail():
    print("----------------------------test_delete_tail---------------------------");

    words = SinglyLinkedList()
    words.Append('foo')
    words.Append('bar')
    words.Append('bim')
    words.Append('baz')
    words.Append('quux')
    
    print("The origin list");
    print("size: {}".format(words.count))
    for word in words:
        print("data: {}".format(word))

    print("Delete the last item in the list")
    words.Delete('quux')
    print("size: {}".format(words.count))
    for word in words:
        print("data: {}".format(word))

    print("append another item")
    words.Append('Quux')
    print("size: {}".format(words.count))
    for word in words:
        print("data: {}".format(word))

def main():
    test_delete_tail()

main()
