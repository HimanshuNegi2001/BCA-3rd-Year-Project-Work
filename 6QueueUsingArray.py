class Queue:
    ele = []
    front = rear = -1

    def enqueue(self, data):
        if self.rear == -1 and self.front == -1:
            self.rear = self.front = 0
            self.ele.append(data)
        else:
            self.rear += 1
            self.ele.append(data)

    def dequeue(self):
        if self.front == -1 and self.rear == -1:
            print("Underflow!")
        else:
            print(f"dequeue element is : {self.ele[self.front]}")
            self.front += 1

    def peek(self):
        if self.front == -1 and self.rear == -1:
            print("Underflow!")
        else:
            print(f"Peek element is: {self.ele[self.front]}")

    def display(self):
        temp = self.front
        if self.front == -1 and self.rear == -1:
            print("Underflow!")
        else:
            while temp <= self.rear:
                print(self.ele[temp], end=" ")
                temp = temp + 1
            print()


qu = Queue()
print("Element in queue")
qu.enqueue(34)
qu.enqueue(14)
qu.enqueue(54)
qu.display()

qu.dequeue()
qu.display()
qu.peek()
