class Stack:
    item = []
    top=-1

    def __init__(self):
        self.item = []
        self.top = -1

    def push(self,element):
        self.top = self.top +1
        self.item.append(element)

    def pop(self):
        if(self.top==-1):
            print("Underflow")
        else:
            self.item.pop();
            self.top = self.top - 1
            print("Last item has been popped from the stack")

    def peek(self):
        if (self.top == -1):
            print("Stack is empty")
        else:
            print(self.item[len(self.item) - 1])

    def display(self):
        if (self.top == -1):
            print("Stack is empty")
        else:
            for i in self.item:
                print(i,end=" ")


s = Stack();
s.push(34)
s.push(1)
s.push(98)
s.push(12)
s.push(100)
s.display()
print()

s.pop()
s.display()
print()

print("peeking element is: ",end=" ")
s.peek()
