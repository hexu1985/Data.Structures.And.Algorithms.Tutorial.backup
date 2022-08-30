from singly_linked_list import SinglyLinkedList

def test():
    words = SinglyLinkedList()
    words.Append('foo')
    words.Append('bar')
    words.Append('bim')
    words.Append('baz')
    words.Append('quux')
    
    print("access by index")
    print("here is a node: {}".format(words[1]))
    
    print("modify by index")
    words[4] = "Quux"
    print("Modified node by index: {}".format(words[4]))
    
    print("This list has {} elements.".format(words.count))
    for word in words:
        print("Got this data: {}".format(word))
    
    if words.Search('foo'):
        print("Found foo in the list.")
    if words.Search('amiga'):
        print("Found amiga in the list.")
    
    print("Now we try to Delete an item")
    words.Delete('bim')
    print("List now has {} elements".format(words.count))
    for word in words:
        print("data: {}".format(word))
    
    print("Delete the first item in the list")
    words.Delete('foo')
    print("size: {}".format(words.count))
    for word in words:
        print("data: {}".format(word))
    
    print("Delete the last item in the list")
    words.Delete('quux')
    print("size: {}".format(words.count))
    for word in words:
        print("data: {}".format(word))

if __name__ == "__main__":
    test()
