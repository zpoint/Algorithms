import random

def quick_sort(arr, start_index, stop_index):
    def partition(start_index, stop_index):
        if (start_index == stop_index):
            return start_index
        pivot = arr[random.randint(start_index, stop_index)]
        while start_index != stop_index:
            while arr[start_index] < pivot:
                start_index += 1
            while arr[stop_index] > pivot:
                stop_index -= 1
            if arr[start_index] == pivot and arr[stop_index] == pivot and start_index != stop_index:
                stop_index -= 1;
                continue;
            arr[start_index], arr[stop_index] = arr[stop_index], arr[start_index]
        return start_index

    middle = partition(start_index, stop_index)
    len_left = middle - start_index
    len_right = stop_index - middle
    if len_left > 1:
        quick_sort(arr, start_index, middle - 1)
    if len_right > 1:
        quick_sort(arr, middle + 1, stop_index)

def pr_arr(arr, string):
    print("\n\t\t%s\n\t\t" % string, end="")
    for i in range(1, len(arr) + 1):
        print("%3d " % arr[i - 1], end="")
        if (i % 10 == 0):
            print("\n\t\t", end="")
    print("")

if __name__ == "__main__":
    arr = [random.randint(0, 99) for i in range(150)]
    pr_arr(arr, "After Initialized")
    quick_sort(arr, 0, len(arr) - 1)
    pr_arr(arr, "After Initialized")

