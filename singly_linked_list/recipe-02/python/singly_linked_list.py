class Node:
    """ A singly-linked node. """
    def __init__(self, data=None):
        self.data = data
        self.next = None

class SinglyLinkedList:
    """ A singly-linked list. """
    def __init__(self):
        """ Create an empty list. """
        self.dummy = Node()
        self.head = self.dummy
        self.head.next = None
        self.tail = self.head
        self.count = 0

    def Append(self, data):
        """ Append an item to the list """
        node = Node(data)
        self.tail.next = node
        self.tail = node
        self.count += 1
    
    def __iter__(self):
        """ Iterate through the list. """
        current = self.head.next
        while current:
            val = current.data
            current = current.next
            yield val

    def Delete(self, data):
        """ Delete a node from the list """
        current = self.head.next
        prev = self.head
        while current:
            if current.data == data:
                prev.next = current.next
                if current == self.tail:
                    self.tail = prev
                self.count -= 1
                return
            prev = current
            current = current.next

    def Search(self, data):
        """ Search through the list. Return True if data is found, otherwise
        False. """
        current = self.head.next
        while current:
            if data == current.data:
                return True
            current = current.next 

        return False

    def __getitem__(self, index):
        if index > self.count - 1:
            raise Exception("Index out of range.")
        current = self.head.next
        for n in range(index):
            current = current.next
        return current.data

    def __setitem__(self, index, value):
        if index > self.count - 1:
            raise Exception("Index out of range.")
        current = self.head.next
        for n in range(index):
            current = current.next
        current.data = value

    def Reverse(self):
        """ Reverse the links of the list """
        current = self.head.next    # 指向头Node: current可能为空
        self.head.next = None       # 重置list头
        self.tail = current if current else self.head   # 记录list尾
        while current:              # 遍历list
            next = current.next;

            # 在list表头插入Node
            current.next = self.head.next;
            self.head.next = current;

            current = next;

    def Sort(self):
        """ Sort the list """
        current = self.head.next    # 指向头Node: current可能为空
        self.head.next = None       # 重置list头
        self.tail = self.head;      # 重置list尾

        while current:              # 遍历list
            next = current.next

            # insert the node into output_list and keep sorted
            output_current = self.head.next
            output_prev = self.head
            while output_current:
                if current.data < output_current.data:
                    break
                output_prev = output_current
                output_current = output_current.next

            current.next = output_current
            output_prev.next = current
            if current.next is None:    # 更新list尾
                self.tail = current

            current = next

