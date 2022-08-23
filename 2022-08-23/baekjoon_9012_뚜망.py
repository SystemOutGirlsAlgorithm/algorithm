for _ in range(int(input())):
    lst = list(input())
    stack = []

    if not len(lst) % 2:
        for l in lst:
            if l == '(':
                stack.append(l)
            elif stack[-1:] == ['(']:
                stack.pop()
            else:
                print('NO')
                break
        else:
            if stack:
                print('NO')
            else:
                print('YES')
    else:
        print('NO')