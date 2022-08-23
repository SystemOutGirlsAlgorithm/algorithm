exp = input()
res = ''
stack = []

for e in exp:
    if e.isalpha():
        res += e
    elif not stack:
        stack.append(e)
    elif e == '(':
        stack.append(e)
    elif e == ')':
        while stack and stack[-1] != '(':
            res += stack.pop()
        stack.pop()
    elif e in '*/':
        while stack[-1:] != ['+'] and stack[-1:] != ['-'] and stack[-1:] != ['(']:
            if not stack: break
            res += stack.pop()
        stack.append(e)
    elif e in '+-':
        while stack[-1:] != ['(']:
            if not stack: break
            res += stack.pop()
        stack.append(e)

while stack:
    res += stack.pop()

print(res)
