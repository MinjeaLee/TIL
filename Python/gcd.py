def GCD(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return 0
    if a % b == 0:
        return b
    else:
        return GCD(b , a%b)
