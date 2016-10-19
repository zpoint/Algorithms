import time
def normal_prime(start, stop):
    count = 0
    if start < 1 or start > stop:
        return -1
    new_start = 2 if start == 1 else  start
    for i in range(new_start, stop + 1):
        j = 2
        isprime = True
        while (j * j <= i):
            if i % j == 0:
                isprime = False
                break
            j += 1
        if isprime:
            count += 1
    return count

def eratos_prime(start, stop):
    count = 0
    prime = 0
    noprime = 1
    if start < 1 or start > stop:
        return -1
    new_start = 2 if start == 1 else start
    matrix = [prime for i in range(start, stop + 1)]
    if start == 1:
        matrix[0] = noprime
    for i in range(new_start, stop + 1): # index = i - start
        if matrix[i - start] == prime:
            count += 1
            j = i * 2
            while (j <= stop):
                if matrix[j - start] == prime:
                    matrix[j - start] = noprime
                j = j + i
    return count


if __name__ == "__main__":
    start = 1
    stop = 9999999
    t1 = time.time()
    result = normal_prime(start, stop)
    t2 = time.time()
    print("normal_prime from %d to %d, result: %d, time: %d seconds" % (start,stop,result,t2- t1))
    t1 = time.time()
    result = eratos_prime(start, stop)
    t2 = time.time()
    print("eratos_prime from %d to %d, result: %d, time: %d seconds" % (start,stop,result,t2- t1))
