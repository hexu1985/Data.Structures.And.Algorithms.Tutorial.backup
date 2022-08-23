class Node:
    """ A singly-linked node. """
    def __init__(self, data=None):
        self.data = data
        self.next = None

class SinglyLinkedList:
    """ A singly-linked list. """
    def __init__(self):
        """ Create an empty list. """
        self.head = None
        self.tail = None
        self.count = 0

    def Append(self, data):
        """ Append an item to the list """
        node = Node(data)
        if self.tail:
            self.tail.next = node
            self.tail = node
        else:
            self.head = node
            self.tail = node
        self.count += 1
    
    def __iter__(self):
        """ Iterate through the list. """
        current = self.head
        while current:
            val = current.data
            current = current.next
            yield val

    def Delete(self, data):
        """ Delete a node from the list """
        current = self.head
        prev = self.head
        while current:
            if current.data == data:
                if current == self.head:
                    self.head = current.next
                else:
                    prev.next = current.next
                self.count -= 1
                return
            prev = current
            current = current.next

    def Reverse(self):
        """ Reverse the links of the list """
        current = self.head
        prev = None
        while current:
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;

        # swap head and tail
        self.head, self.tail = self.tail, self.head

    def Search(self, data):
        """ Search through the list. Return True if data is found, otherwise
        False. """
        current = self.head
        while current:
            if data == current.data:
                return True
            current = current.next 

        return False

    def __getitem__(self, index):
        if index > self.count - 1:
            raise Exception("Index out of range.")
        current = self.head
        for n in range(index):
            current = current.next
        return current.data

    def __setitem__(self, index, value):
        if index > self.count - 1:
            raise Exception("Index out of range.")
        current = self.head
        for n in range(index):
            current = current.next
        current.data = value

def test():
    print("----------------------------test---------------------------");

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

def test_reverse():
    print("----------------------------test_reverse---------------------------");

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
    test_reverse()
