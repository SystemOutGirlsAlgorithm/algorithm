while True:
    n = int(input())
    if n == 0:
        break
    
    print("{", end="")
    n -= 1
    three = 1
    start = True
    while n > 0:
        if n % 2 == 1:
            if start:
                print(" ", end="")
                print(three, end="")
                start = False
            else:
                print(", ", end="")
                print(three, end="")
        three *= 3
        n //= 2
    print(" }")

