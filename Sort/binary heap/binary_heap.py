class binary_heap(object):
    def __init__(self):
        self.size = 0
        self.arr = []

    def parent(self, index):
        return (index+1) // 2 - 1
    def left(self, index):
        return (index+1)*2 - 1
    def right(self, index):
        return (index+1)*2

    def sift_up(self, index):
        if index < 0 or index >= self.size:
            return False
        while (index > 0):
            parent = self.arr[self.parent(index)]
            if parent < self.arr[index]:
                self.arr[index], self.arr[self.parent(index)] = parent, self.arr[index]
                index = self.parent(index)
            else:
                break
        return True

    def sift_down(self, index):
        if (index < 0 or index >= self.size):
            return False
        while (index < self.size):
            left_index = self.left(index)
            right_index = self.right(index)
            max_index = index
            if (left_index < self.size and self.arr[left_index] > self.arr[max_index]):
                max_index = left_index
            if (right_index < self.size and self.arr[right_index] > self.arr[max_index]):
                max_index = right_index
            if max_index != index:
                self.arr[max_index], self.arr[index] = self.arr[index], self.arr[max_index]
                index = max_index
            else:
                break
        return True

    def insert(self, value):
        self.arr.append(value)
        self.size += 1
        self.sift_up(self.size-1)

    def get_max(self):
        if self.size == 0:
            return None
        return self.arr[0]

    def get_size(self):
        return self.size

    def is_empty(self):
        return True if self.get_size() == 0 else False

    def extract_max(self):
        if self.size <= 0:
            return None
        ret_val = self.arr[0]
        self.arr[0] = self.arr[self.size-1]
        self.size -= 1
        self.sift_down(0)
        return ret_val

    def remove(self, index):
        if index >= self.size or index < 0:
            return None
        ret_val = self.arr[index]
        self.arr[index] = float('inf')
        self.sift_up(index)
        self.extract_max()
        return ret_val

    def heapify(self):
        if self.size <= 0:
            return False
        for i in range(self.parent(self.size - 1), -1, -1):
            self.sift_down(i)
        return True

    def heap_sort(self):
        if self.size < 0:
            return False
        for i in range(self.size-1, -1, -1):
            self.arr[i] = self.extract_max()
        return True

    def pr_heap(self, string="", length=None):
        if length == None:
            length = self.size
        print("\n\t\tprint heap, %s\n\t\t" % (string,), end="")
        for i in range(1, length+1):
            print("%d\t" % (self.arr[i-1], ), end="")
            if (i % 10 == 0):
                print("\n\t\t", end="")
        print("")

if __name__ == "__main__":
    import random
    heap = binary_heap()
    arr = [random.randint(0,99) for i in range(100)]
    heap.arr = arr
    heap.size = len(arr)
    heap.pr_heap("After Insert 100 random numbers range(0, 99)")
    heap.heapify()
    heap.pr_heap("After heapify")
    heap.heap_sort()
    heap.pr_heap("After heap sort", len(arr))
