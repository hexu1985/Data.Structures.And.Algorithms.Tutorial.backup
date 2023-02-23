class Node:
    """ A Doubly-linked lists' node. """
    def __init__(self, data=None):
        self.data = data
        self.next = self
        self.prev = self


class DoublyLinkedList(object):
    def __init__(self):
        self.dummy = Node()
        self.nil = self.dummy
        self.count = 0

    def Append(self, data):
        """ Append an item to the list. """
        node = Node(data)

        # insert before nil.
        current = self.nil
        prev_node = current.prev

        node.prev = prev_node
        node.next = current

        prev_node.next = node
        current.prev = node

        self.count += 1

    def iter(self):
        """ Iterate through the list. """
        current = self.nil.next
        while current != self.nil:
            val = current.data
            current = current.next
            yield val

    def reverse_iter(self):
        """ Iterate backwards through the list. """
        current = self.nil.prev
        while current != self.nil:
            val = current.data
            current = current.prev
            yield val

    def Delete(self, data):
        """ Delete a node from the list. """
        current = self.nil.next
        while current != self.nil:
            if current.data == data:
                prev_node = current.prev
                succ_node = current.next

                prev_node.next = succ_node
                succ_node.prev = prev_node

                self.count -= 1
                return True
            current = current.next
        return False

    def Search(self, data):
        """Search through the list. Return True if data is found, otherwise False."""
        current = self.nil.next
        while current != self.nil:
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

        # insert before nil.next.
        current = self.nil.next
        prev_node = current.prev

        node.prev = prev_node
        node.next = current

        prev_node.next = node
        current.prev = node

        self.count += 1

    def Reverse(self):
        """ Reverse linked list. """
        current = self.nil.next
        while current != self.nil:
            # swap current.next and current.prev
            current.prev, current.next = current.next, current.prev
            current = current.prev

        # Now reverse the order of head and tail
        self.nil.next, self.nil.prev = self.nil.prev, self.nil.next

    def __getitem__(self, index):
        if index > self.count - 1:
            raise Exception("Index out of range.")
        current = self.nil.next # Note subtle change
        for n in range(index):
            current = current.next
        return current.data

    def __setitem__(self, index, value):
        if index > self.count - 1:
            raise Exception("Index out of range.")
        current = self.nil.next # Note subtle change
        for n in range(index):
            current = current.next
        current.data = value


