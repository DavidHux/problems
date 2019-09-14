def cmp():
    a = int(input())
    b = int(input())
    sma, big = (a, b) if a < b else (b, a)
    tmp = big % sma
    while tmp != 0:
        big = sma
        sma = tmp
        tmp = big % sma
    print(sma)

if __name__ == "__main__":
    cmp()
    