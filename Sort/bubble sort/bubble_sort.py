import random

def bubble_sort(arr):
    size = len(arr)
    for i in range(size - 1):
        for j in range(size - 1 - i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr;

def pr_arr(arr, string):
    print("\n\t\tsize:{}, {}\n\t\t".format(len(arr), string), end='')
    for i in range(len(arr)):
        print(arr[i], "\t", end='')
        if i != 0 and i % 10 == 0:
            print("\n\t\t", end='')
    print("")

if __name__ == "__main__":
    arr = [random.randint(0, 100) for i in range(100)]
    pr_arr(arr, "initialized arr");
    pr_arr(bubble_sort(arr), "After bubble sort:")

