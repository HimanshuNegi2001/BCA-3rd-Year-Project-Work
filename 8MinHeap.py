def heapify(arr, i):
    size = len(arr)
    smallest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < size and arr[smallest] > arr[l]:
        smallest = l
    if r < size and arr[smallest] > arr[r]:
        smallest = r
    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i]
        heapify(arr, smallest)


def insert(arr, key):
    size = len(arr)
    if size == 0:
        arr.append(key)
    else:
        arr.append(key)
        for i in range(size - 1, -1, -1):
            heapify(arr, i)

def delete(arr,value):
    print("After deleting an element: "+str(value))
    size = len(arr)
    i=0
    flag = 0
    for i in range(0,size):
        if value == arr[i]:
            flag += 1
            break
    if flag == 0:
        print(f"{value} is not present in heap")
        return

    arr[i], arr[size-1] = arr[size-1], arr[i]
    arr.remove(value)
    for i in range(size - 1, -1, -1):
        heapify(arr, i)

def display(arr):
    print("Min-heap array: " + str(arr))
    print()


array1 = []

insert(array1, 9)
insert(array1, 12)
insert(array1, 1)
insert(array1, 20)
insert(array1, 13)
insert(array1, 19)
insert(array1,50)
insert(array1,100)

display(array1)
delete(array1,13)
display(array1)

delete(array1,25)
display(array1)