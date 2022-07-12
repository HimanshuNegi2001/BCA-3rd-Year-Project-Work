class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class StackList:
    def __init__(self):
        self.top = 0

    def push(self, key):
        new_node = Node(key)
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        temp = self.top
        if self.top == 0:
            print("Underflow!")
        else:
            print(f"Pop element is: {self.top.data}")
            self.top = self.top.next
            del temp

    def peak(self):
        if self.top == 0:
            print("Underflow!")
        else:
            print(f"Peek element is: {self.top.data} ")

    def display(self):
        if self.top == 0:
            print("Underflow!")
        else:
            print("Element in stack: ")
            temp = self.top
            while temp != 0:
                print(temp.data)
                temp = temp.next


stack = StackList()
stack.push(34)
stack.push(14)
stack.push(89)
stack.push(50)
stack.push(79)
stack.display()

stack.pop()
stack.display()

stack.peak()
