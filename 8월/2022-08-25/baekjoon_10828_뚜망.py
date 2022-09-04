import sys

class Stack:
    def __init__(self):
        self.stack = [0] * 10000
        self._top = -1

    def push(self, item):
        self._top += 1
        self.stack[self._top] = item

    def pop(self):
        if not self.empty():
            self._top -= 1
            return self.stack[self._top+1]
        return -1

    def empty(self):
        return int(self._top == -1)

    def top(self):
        if not self.empty():
            return self.stack[self._top]
        return -1

n = int(input())
stack1 = Stack()
for _ in range(n):
    t = sys.stdin.readline().split()
    o = t[0]

    if o == 'push':
        stack1.push(t[1])
    elif o == 'size':
        print(len(stack1.stack[:stack1._top + 1]))
    elif o == 'empty':
        print(stack1.empty())
    elif o == 'pop':
        print(stack1.pop())
    else: # o == 'top'
        print(stack1.top())
