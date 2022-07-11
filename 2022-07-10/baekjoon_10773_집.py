import sys

# input: total number of inputs
n = int(sys.stdin.readline())

stack = []
# looping to push or pop values
for i in range(n):
    new_num = int(sys.stdin.readline())
    if new_num != 0:
        stack.append(new_num)
    else:
        stack.pop()

# looping to calculate sum
total = sum(stack)

print(total)