
def pr_matrix(matrix, str1, str2):
    ret_str = ""
    for i in matrix:
        for j in i:
            print("%d  "% (j,), end="")
        print("")
    i = len(matrix) - 1
    j = len(matrix[0]) - 1
    print("Result:", end="")
    while (i != 0 and j != 0):
        curr = matrix[i][j]
        left = matrix[i][j - 1]
        up = matrix[i - 1][j]
        if curr == left:
            j -= 1
        elif curr == up:
            i -= 1
        else:
            j -= 1
            i -= 1
            ret_str += str1[j]
            print("%c  " % str1[j], end="")
    print("")
    return ret_str

def LCS(str1, str2):
    lena = len(str1)
    lenb = len(str2)
    matrix = [[0] * (lena + 1) for i in range(lenb + 1)]
    for i in range(1, lenb + 1):
        for j in range(1, lena + 1):
            if str1[j - 1] == str2[i - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
    return pr_matrix(matrix, str1, str2)

if __name__ == "__main__":
    a = "abcdeffff"
    b = "acbcfff"
    print("%s\n%s\n" % (a, b), end="")
    LCS(a, b)
    
