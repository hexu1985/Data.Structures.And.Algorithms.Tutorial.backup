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
                if current == self.tail:
                    self.tail = prev if self.head else None
                self.count -= 1
                return
            prev = current
            current = current.next

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

    def Sort(self):
        """ Sort the list """
        # insertion sort
        output_list = SinglyLinkedList()
        current = self.head
        while current:
            next = current.next

            # insert the node into output_list and keep sorted
            output_current = output_list.head 
            output_prev = output_list.head
            while output_current:
                if current.data < output_current.data:
                    break
                output_prev = output_current
                output_current = output_current.next

            current.next = output_current
            if output_current == output_list.head:
                output_list.head = current
            else:
                output_prev.next = current

            if current.next is None:
                output_list.tail = current

            current = next

        self.head = output_list.head
        self.tail = output_list.tail

