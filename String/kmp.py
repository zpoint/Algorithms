def KMP(string, sub_str):
    def generate_prefix():
        nonlocal sub_str
        length = len(sub_str)
        ret_arr = [0 for i in range(length)]
        j = 0
        i = 1
        while i < length:
            if sub_str[j] == sub_str[i]:
                ret_arr[i] = j + 1
                i += 1
                j += 1
            elif j == 0:
                ret_arr[i] = 0
                i += 1
            else:
                j = ret_arr[j - 1]
        return ret_arr
    i = 0
    j = 0
    length_str = len(string)
    length_sub = len(sub_str)
    if length_sub > length_str:
        return
    prefix_arr = generate_prefix()
    while i < length_str:
        if string[i] == sub_str[j]:
            i += 1
            j += 1
        elif j == 0:
            i += 1
        else:
            j = prefix_arr[j - 1]
        if j == length_sub:
            print("match_index: %d" % (i - length_sub,))
            i = i - length_sub + 1
            j = 0


if __name__ == "__main__":
    a = "banana"
    b = "ana"
    print("a: %s, b: %s" % (a, b))
    KMP(a, b)
