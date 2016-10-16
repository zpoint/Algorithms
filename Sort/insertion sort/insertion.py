import random

def insertion_sort(arr):
    if len(arr) > 1:
    	for i in range(len(arr)):
            j = i - 1
            while arr[j] > arr[j + 1] and j >= 0:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                j -= 1
                
    return arr

def pr_arr(arr, string):
    print("\n\t\t%s\n\t\t" % string, end="")
    for i in range(len(arr)):
        print("%3d" % (arr[i]), end='');
        if (i != 0 and i % 10 == 0):
            print("\n\t\t", end="");
    print("")

if __name__ == "__main__":
    arr = [random.randint(0, 9) for i in range(150)]
    pr_arr(arr, "Initialized");
    pr_arr(insertion_sort(arr), "After insertion_sort")

