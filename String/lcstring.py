def lcstring(str1, str2):
    lena = len(str1)
    lenb = len(str2)
    maxval = 0
    maxi = 0
    maxj = 0
    matrix = [[0] * (lena + 1) for i in range(lenb + 1)]
    for i in range(1, lenb + 1):
        for j in range(1, lena + 1):
            if str1[j - 1] == str2[i - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
                if matrix[i][j] > maxval:
                    maxval = matrix[i][j]
                    maxi = i
                    maxj = j
    result = ""
    while (maxi > 0 and maxj > 0):
        result = str1[maxj - 1] + result
        maxi -= 1
        maxj -= 1
    return result

if __name__ == "__main__":
    a = "12345678999999987654321"
    b = "87654321"
    result = lcstring(a, b)
    print("stringA:\t%s\n stringB:\t%s\n lsctring:\t%s\n length:\t%s" % (a, b, result, len(result)));
