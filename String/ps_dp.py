def palindrome_substring(string):
    matrix = [[True] * len(string) for i in range(len(string))]
    maxlen = -1
    firstIndex = -1
    lastIndex = -1
    for distance in range(1, len(string)):
        for i in range(len(string) - distance):
            curr = True if string[i] == string[i + distance] else False
            middle = matrix[i + distance - 1][i + 1] if distance > 1 else True
            if not (curr == True and middle == True):
                matrix[i + distance][i] = False
            elif distance + 1 > maxlen:
                maxlen = distance + 1
                firstIndex = i
                lastIndex = i + distance
    print("\n\t\tstring: %s, maxsubstring: %s, len: %d\n" % (string, string[firstIndex: lastIndex + 1], maxlen))


if __name__ == "__main__":
    palindrome_substring("11221")


