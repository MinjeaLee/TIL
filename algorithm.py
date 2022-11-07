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

# gdc(최대 공약수)
def gcd(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return 0
    else:
        while b != 0:
            n = a % b
            a = b
            b = n
        result = a

# lcm(최소 공배수)
def lcm(a, b):
    result = a * b / gcd(a,b)
    return result
        

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
    if div == 0:
        print("Prime")
    div = 0

# 숫자 반대로 - 1 // ex) 1234 -> 4321

def reverse_int(num):
    result = 0
    while num > 0:
        result *= 10
        check = num % 10
        result += check
        num /= 10

# 숫자 추출, 숫자 반대로 하나 씩 출력

def invert_num(num):
    while num > 0:
        one_num = num % 10
        num /= 10
        print(one_num,"\n")


