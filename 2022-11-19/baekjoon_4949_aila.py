inputList = list(input())
while (inputList != ['.']):
    parenthesises = []
    answer = 'yes'
    for j in inputList:
        inputStr = 0
        if j == '(':
            inputStr = 1
        elif j == ')':
            inputStr = 2
        elif j == '[':
            inputStr = 3
        elif j == ']':
            inputStr = 4
        if inputStr:
            if inputStr % 2:
                parenthesises.append(inputStr)
            elif len(parenthesises) and inputStr - 1 == parenthesises[-1]:
                parenthesises.pop()
            elif inputStr % 2 == 0:
                answer = 'no'
    if len(parenthesises):
        answer = 'no'
    print(answer)
    inputList = list(input())
