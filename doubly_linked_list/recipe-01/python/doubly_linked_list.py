class Node:
    """ A Doubly-linked lists' node. """
    def __init__(self, data=None):
        self.data = data
        self.next = None
        self.prev = None


class DoublyLinkedList(object):
    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    def Append(self, data):
        """ Append an item to the list. """
        node = Node(data)
        if self.head is None:
            self.head = node
            self.tail = self.head
        else:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node
        self.count += 1

    def iter(self):
        """ Iterate through the list. """
        current = self.head #note subtle change
        while current:
            val = current.data
            current = current.next
            yield val

    def reverse_iter(self):
        """ Iterate backwards through the list. """
        current = self.tail
        while current:
            val = current.data
            current = current.prev
            yield val

    def Delete(self, data):
        """ Delete a node from the list. """
        current = self.head
        while current:
            if current.data == data:
                if current.prev:    # current is not head node
                    current.prev.next = current.next
                else:
                    self.head = current.next
                if current.next:    # current is not tail node
                    current.next.prev = current.prev
                else:
                    self.tail = current.prev
                self.count -= 1
                return True
            current = current.next
        return False

    def Search(self, data):
        """Search through the list. Return True if data is found, otherwise False."""
        current = self.head
        while current:
            if data == current.data:
                return True
            current = current.next 

        return False

    def PrintFoward(self):
        """ Print nodes in list from first node inserted to the last . """
        for node in self.iter():
            print(node)

    def PrintBackward(self):
        """ Print nodes in list from latest to first node. """
        for node in self.reverse_iter():
            print(node)

    def InsertHead(self, data):
        """ Insert new node at the head of linked list. """
        node = Node(data)
        if self.head:   # list not empty 
            self.head.prev = node
            node.next = self.head
            self.head = node
        else:
            self.tail = self.head = node
        self.count += 1

    def Reverse(self):
        """ Reverse linked list. """
        current = self.head
        while current:
            # swap current.next and current.prev
            current.prev, current.next = current.next, current.prev
            current = current.prev

        # Now reverse the order of head and tail
        self.head, self.tail = self.tail, self.head

    def __getitem__(self, index):
        if index > self.count - 1:
            raise Exception("Index out of range.")
        current = self.head # Note subtle change
        for n in range(index):
            current = current.next
        return current.data

    def __setitem__(self, index, value):
        if index > self.count - 1:
            raise Exception("Index out of range.")
        current = self.head # Note subtle change
        for n in range(index):
            current = current.next
        current.data = value


