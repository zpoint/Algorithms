import random

def selection_sort(arr):
    for i in range(len(arr)):
        min_arr = arr[i]
        min_index = i
        for j in range(i + 1, len(arr)):
            if (arr[j] < min_arr):
                min_arr = arr[j]
                min_index = j
        if min_index != i:
            arr[i], arr[min_index] = arr[min_index], arr[i]

def pr_arr(arr, string):
    print("\n\t\tsize: %d %s\n\t\t" % (len(arr), string), end="")
    for i in range(1, len(arr) + 1):
        print("%3d " % arr[i - 1], end = "")
        if (i % 10 == 0):
            print("\n\t\t", end="")
    print("")

if __name__ == "__main__":
    arr = [random.randint(0, 99) for i in range(150)]
    pr_arr(arr, "Initialized")
    selection_sort(arr)
    pr_arr(arr, "After selection_sort")
