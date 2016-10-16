import random

def merge(left, right):
    lsize = len(left)
    rsize = len(right)
    indexL = 0
    indexR = 0
    arr = []
    for i in range(lsize + rsize):
        if indexL >= lsize:
            arr.append(right[indexR])
            indexR += 1
        elif indexR >= rsize:
            arr.append(left[indexL])
            indexL += 1
        else:
            if left[indexL] > right[indexR]:
                arr.append(right[indexR])
                indexR += 1
            else:
                arr.append(left[indexL])
                indexL += 1
    return arr

def merge_sort(arr):
    length = len(arr)
    if length == 1:
        return arr;
    Llen = int(length / 2)
    left = merge_sort(arr[:Llen])
    right = merge_sort(arr[Llen:])
    return merge(left, right)

def pr_arr(arr, string):
    print("\n\t\tsize: %d, %s" % (len(arr), string), end="")
    for i in range(len(arr)):
        print("%3d " % arr[i], end="")
        if (i % 10 == 0):
            print("\n\t\t", end="")
    print("")

if __name__ == "__main__":
    arr = [random.randint(0, 99) for i in range(150)]
    pr_arr(arr, "Initial")
    pr_arr(merge_sort(arr), "After merge_sort:")
