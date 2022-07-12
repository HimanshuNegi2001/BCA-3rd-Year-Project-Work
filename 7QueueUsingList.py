class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.front = 0
        self.rear = 0

    def enqueue(self, key):
        new_node = Node(key)
        new_node.next = None
        if self.front == 0 and self.rear == 0:
            self.front = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node

    def dequeue(self):
        if self.front == 0 and self.rear == 0:
            print("Underflow!")
        elif self.front == self.rear:
            print(f"Dequeue element is: {self.front.data}")
            self.front = self.rear = 0

        else:
            print(f"Dequeue element is: {self.front.data}")
            self.front = self.front.next

    def peek(self):
        if self.front == 0 and self.rear == 0:
            print("Underflow!")
        else:
            print(f"Peek element is: {self.front.data}")

    def display(self):
        temp = self.front
        if self.front == 0 and self.rear == 0:
            print("Underflow!")
        else:
            print("Element is queue: ", end=" ")
            while temp is not None:
                print(temp.data, end=" ")
                temp = temp.next
            print()


ql = Queue()
ql.enqueue(34)
ql.enqueue(64)
ql.enqueue(94)
ql.enqueue(14)
ql.display()
ql.dequeue()
ql.display()
ql.peek()
