import time

def pr_matrix(matrix):
    for i in matrix:
        for j in i:
            print("%2d " % j, end="")
        print("")

def editDistanceRecursive(a, b):
    if len(a) == 0:
        return len(b)
    if len(b) == 0:
        return len(a)
    edit = 0 if a[-1] == b[-1] else 1
    return min(editDistanceRecursive(a[:-1], b[:-1]) + edit,
               editDistanceRecursive(a[:-1], b) + 1,
               editDistanceRecursive(a, b[:-1]) + 1)

def editDistance(a, b):
    matrix = []
    for i in range(len(a) + 1):
        matrix.append([0] * (len(b) + 1))
    for i in range(len(a) + 1):
        matrix[i][0] = i
    for i in range(len(b) + 1):
        matrix[0][i] = i
    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            horize = matrix[i][j - 1] + 1
            vert = matrix[i -1][j] + 1
            distdlg = matrix[i - 1][j - 1] if a[i - 1] == b[j - 1] else matrix[i -1][j - 1] + 1
            matrix[i][j] = min(horize, vert, distdlg)
    #pr_matrix(matrix)
    return matrix[-1][-1]


if __name__ == "__main__":
    a = "Oh my gooood"
    b = "hh mv goooid"
    print("\n\t\t%s\n\t\t%s\n\t\t" % (a, b), end="")
    t1 = time.time()
    print("editDistanceRecursive result:", editDistanceRecursive(a, b), end="")
    t2 = time.time()
    print("\tCost: %.5f" % (t2 - t1), "seconds\n\t\t", end="")
    t1 = time.time()
    print("Dynamic Programming Editdistance result: ", editDistance(a, b), end="")
    t2 = time.time()
    print("\tCost: %.5f" % (t2 - t1), "seconds\n\t\t", end="")

