import sys
sys.stdin = open('input.txt')

N = int(input())
stack = [0] * 10000    # 스택
top = -1    # top

for _ in range(N):
    input_order = list(sys.stdin.readline().split())    # 실행할 명령 / 그냥 input 쓰면 시간초과

    order = input_order[0]
    if order == 'push':
        top += 1
        stack[top] = input_order[1]

    elif order == 'pop':
        if top > -1:
            top -= 1
            X = stack[top + 1]
            print(X)
        else:
            print(-1)

    elif order == 'size':
        print(top + 1)

    elif order == 'empty':
        if top == -1:
            print(1)
        else:
            print(0)

    elif order == 'top':
        if top > -1:
            print(stack[top])
        else:
            print(-1)

