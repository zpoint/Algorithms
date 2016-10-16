import random

def insertion_sort(arr):
    for i in range(len(arr)):
        for j in range(i):
            if (arr[j] > arr[i]):
                tmp = arr[i]
                for k in range(i, j, -1):
                    arr[k] = arr[k - 1]
                arr[j] = tmp;
                break;
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

