class quicksort:
    def __init__(self, arr):
        self.array = arr
    def __str__(self):
        return str(self.array)
    
    def isNumber(self,x):
        try:
            int(x)
        except TypeError:
            return False
        return True

    def partition(self, start = 0, end = None):
        A = self.array
        last = end if self.isNumber(end) else len(A) - 1
        pivot = A[last]
        return_index = start - 1
        for traverse_index in range(start, last):
            if A[traverse_index] <= pivot:
                return_index += 1
                A[return_index], A[traverse_index] = A[traverse_index], A[return_index]
        A[return_index + 1], A[last] = A[last], A[return_index + 1]
        return return_index + 1

    def partition_dec(self, start = 0, end = None):
        A = self.array
        last = end if self.isNumber(end) else len(A) - 1
        pivot = A[last]
        return_index = start - 1
        for traverse_index in range(start, last):
            if A[traverse_index] >= pivot:
                return_index += 1
                A[return_index], A[traverse_index] = A[traverse_index], A[return_index]
        A[return_index + 1], A[last] = A[last], A[return_index + 1]
        return return_index + 1
     
    def partition2(self, start = 0, end = None):
        A = self.array
        last = end - 1 if self.isNumber(end) else len(A) - 1
        pivot = A[last]
        pivot_index = start
        repetition = 0
        for i in range(start, last):
            value = A[i]
            if value == pivot:
                repetition += 1
            if value <= pivot:
                A[i], A[pivot_index] = A[pivot_index], A[i]
                pivot_index += 1
        A[last], A[pivot_index] = A[pivot_index], A[last]
        return pivot_index - repetition // 2
            
    def quicksort_inc(self,start = 0, end = None):
        A = self.array
        last = end if self.isNumber(end) else len(A) - 1
        #print("Begin:quicksort(",A, start, end,")")
        #print("start:%d, last:%d" % (start,last))
        if start < last:
            """    
            print("start < last  ====>  %d < %d" % (start,last))
            print("Before partition:")
            print("A:",A)
            """
            new_pivot_index = self.partition(start, last)
            """
            print("After partiton: new_pivot_index",new_pivot_index)
            print("A:",A)
            print("quicksort(",A, start, new_pivot_index - 1,")")
            """
            self. quicksort_inc(start, new_pivot_index - 1)
            #print("quicksort(",A, new_pivot_index + 1, last,")")
            self.quicksort_inc(new_pivot_index + 1, last)

    def quicksort_dec(self, start = 0, end = None):
        A = self.array
        last = end if self.isNumber(end) else len(A) - 1
        if start < last:
            """
            print("start < last  ====>  %d < %d" % (start,last))
            print("Before partition:")
            print("A:",A)
            """
            new_pivot_index = self.partition_dec(start, last)
            """
            print("After partiton: new_pivot_index",new_pivot_index)
            print("A:",A)
            print("quicksort(",A, start, new_pivot_index - 1,")")
            """
            self.quicksort_dec(start, new_pivot_index - 1)
            #print("quicksort(",A, new_pivot_index + 1, last,")")
            self.quicksort_dec(new_pivot_index + 1, last)

    def quicksort_dec_slow(self, start = 0, end = None):
        A = self.array
        last = end if self.isNumber(end) else len(A) - 1
        if start < last:
            new_pivot_index = self.partition(start, last)
            ##exchange pivot_index's left and right
            new_pivot_index = self.exchange(new_pivot_index, start, last)
            self.quicksort_dec(start, new_pivot_index - 1)
            self.quicksort_dec(new_pivot_index + 1, last)
            

    def exchange(self, pivot_index, start, end):
        A = self.array
        arr_prev = []
        arr_next = []
        pivot_value = A[pivot_index]
        k = 0
        for i in range(start, pivot_index):
            arr_prev.append(A[i])
        for i in range(pivot_index + 1, end + 1):
            arr_next.append(A[i])
        j = start + len(arr_next)
        A[j] = pivot_value
        for i in range(start, j):
            A[i] = arr_next[k]
            k += 1
        k = 0
        for i in range(j + 1, end + 1):
            A[i] = arr_prev[k]
            k += 1
        return j
    
import copy
A = [2,8,7,1,3,5,6,4]
B = copy.deepcopy(A)
qa = quicksort(A)
print(qa.quicksort_dec())
print(A)