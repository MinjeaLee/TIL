#swap
def swap(a, b):
    c = a
    a = b
    b = c
    return a, b

#len()
def len(a):
    n = 0
    for i in a:
        n += 1
    return n

#list()
def list(a):
    result = []
    for i in a:
        result.append(i)
    return result

#sort() only list
def sort_list(a):
    for i in range(len(a) -1):
        for j in range(i+1, len(a)):
            if a[j] < a[i]:
                a[j], a[i] = a[i], a[j]
    return a
#sort() only str

#reverse()
def reverse_list(a):
    for i in range(len(a)-1):
        max = i
        for j in range(i + 1, len(a)):
            if a[max] < a[j]:
                max = j
        a[i], a[max] = a[max], a[i]
    return a
    


#abs()
def abs(a):
    if a == 0:
        return 0
    elif a < 0:
        return -a
    else:
        return a

#max, min
#sum

#gcd 제귀함수 사용
def GCD(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return 0
    if a % b == 0:
        return b
    else:
        return GCD(b , a%b)

# gdc
def gcd(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return 0
    while b != 0:
        n = a % b
        a = b
        b = n
    result = a
        

# 소인수분해
def Prime_factorization(num):
    for i in range(2, num + 1):
        while num % i == 0:
            num /= i
            print("{} *".format(i))

# 소수 판별
def Distingusih_of_Prime(num):
    div = 0
    for i in range(2, num + 1):
        if num % i:
            div = 1
    if !(div):
        print("Prime")
    div = 0

#reversse
    

