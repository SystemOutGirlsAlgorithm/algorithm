# 6
# (())())
# (((()())()
# (()())((()))
# ((()()(()))(((())))()
# ()()()()(()()())()
# (()((())()(

T = int(input())
for i in range(T):
    inputList = list(input())
    parenthesises = []
    answer = 'YES'
    for j in inputList:
        inputStr = 'open' if j == '(' else 'close'
        if (inputStr == 'open'):
            parenthesises.append('open')
        elif (len(parenthesises) and inputStr == 'close'):
            parenthesises.pop()
        elif (inputStr == 'close'):
            answer = 'NO'
    if (len(parenthesises)):
        answer = 'NO'
    print(answer)
