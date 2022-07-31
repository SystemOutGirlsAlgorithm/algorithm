import sys


n = int(input())

stack = []

for i in range(n):
    cmd = list(sys.stdin.readline().rstrip().split())

    if cmd[0] == 'push':
        # push the value cmd[1] to the stack
        stack.append(int(cmd[1]))
    elif cmd[0] == 'pop':
        # pop the value from the stack
        # case 1. empty stack
        length = len(stack)
        if length == 0:
            print(-1)
        else:
            print(stack[-1])
            stack = stack[:length-1]
    elif cmd[0] == 'size':
        # for loop
        print(len(stack))
    elif cmd[0] == 'empty':
        length = len(stack)
        if length == 0:
            print(1)
        else:
            print(0)
    elif cmd[0] == 'top':
        length = len(stack)
        if length == 0:
            print(-1)
        else:
            print(stack[-1])
