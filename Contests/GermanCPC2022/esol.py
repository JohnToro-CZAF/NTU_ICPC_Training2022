from sys import stdin

n = int(stdin.readline().strip())

# 1 0
# 0 1
# 0.5 0.5
# 0.25 0.75
# 0.375 0.625
# 0.3125 0.6875


# 1/3 + 2/3 * (-1/2)**(n-1)

def twoPower(x):
    if x == 0:
        return 1
    
    if x % 2 == 0:
        return twoPower(x // 2) ** 2
    else:
        return (twoPower(x // 2) ** 2) / 2

if n == 1:
    print(100, 0)

elif n == 2:
    print(0, 100)

else:
    twoP = twoPower(n-1)
    even = (n-1) % 2 + 2
    a = 1/3 + 2/3 * ((-1) ** even) * twoP
    b = 1 - a
    print(a * 100, b * 100)