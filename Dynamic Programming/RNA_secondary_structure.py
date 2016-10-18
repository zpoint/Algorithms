def pr_matrix(matrix):
    print("")
    for i in range(len(matrix)):
        print("\t\t%2d" % (i + 1,), " ", matrix[i])
    print("     \n\t\t", end="")
    for i in range(len(matrix[0])):
        print("%2d " % (i+1,), end="")
    print("\n\t\t", end="")

def pr_result(matrix, string, maxnum):
    def ninset(tup, setA):
        inside = False
        for i in tup:
            if i in setA:
                inside = True
        if not inside:
            return True
        return False
    def tree_recursive(num_list, index, setA, result):
        nonlocal index_list
        if index < 0:
            print("\n\t\t", end="")
            for each_tup in result:
                print("(%d, %d) " % (each_tup[0] + 1, each_tup[1] + 1), end="")
            return
        for each_tup in num_list[index]:
            if ninset(each_tup, setA):
                index_list[index] = 1
                setB = setA | set(each_tup)
                resultB = [i for i in result]
                resultB.append(each_tup)
                tree_recursive(num_list, index - 1, setB, resultB)
            elif (each_tup == num_list[index][-1] and index_list[index] == 0):
                tree_recursive(num_list, index - 1, setA, result)

    if maxnum == 0:
        print("\n\t\tNo results!")
        return
    print("\n\t\tmatch: %s" % (string,), end="")
    num_list = [[] for i in range(maxnum)]
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            current_num = matrix[i][j]
            if current_num != 0:
                num_list[current_num - 1].append((i, j))

    index_list = [0] * len(num_list)
    index_list[-1] = 1
    for tup in num_list[-1]:
        setA = set(tup)
        result = []
        result.append(tup)
        tree_recursive(num_list, len(num_list) - 2, setA, result)



def RNA_match(string):
    def max_t(matrix, start, end):
        maxnum = 0
        for t in range(start + 1, end):
            summ = matrix[start][t - 1] + matrix[t + 1][end]
            if summ > maxnum:
                maxnum = summ
        return maxnum
    def ismatch(a, b):
        if a == "A" and b == "U":
            return 1
        elif a == "U" and b == "A":
            return 1
        elif a == "G" and b == "C":
            return 1
        elif a == "C" and b == "G":
            return 1
        return 0

    length = len(string)
    matrix = []
    maxnum = 0
    for i in range(length):
        matrix.append([0]*length)
    #pr_matrix(matrix)
    for k in range(5, length):
        for i in range(length-k):
            j = i + k
            match = ismatch(string[i], string[j])
            result = max(matrix[i][j - 1], match + max_t(matrix, i, j))
            if result > maxnum:
                maxnum = result
            matrix[i][j] = result
    pr_matrix(matrix)
    pr_result(matrix, string, maxnum)
    print("")


if __name__ == "__main__":
    RNA = "ACCGGUAGUC"
    RNA_match(RNA)
