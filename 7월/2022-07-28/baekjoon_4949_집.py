import sys


# stack or hash?

# n 이 주어졌을 때 시간단축 가능
# data = [sys.stdin.readline().strip() for i in range()]

# rstrip(): 인자 전달하지 않으면 공백 제거, 인자 전달시 오른쪽의 해당 인자들 제거
datasets = []
while True:
    dataset = sys.stdin.readline().rstrip()
    if dataset == ".":
        break
    elif dataset == "":
        datasets.append("\n")
    else:
        datasets.append(dataset)

for data in datasets:
    no = 0
    stack = []
    for letter in data:
        # if left, push it into the stack
        if letter == '(' or letter == '[':
            stack.append(letter)
        # if right, pop the left from the stack
        elif letter == ')' or letter == ']':
            # if the stack is empty
            if len(stack) == 0:
                no = -1  # print("no")
                break
            # if the stack is not empty
            else:
                pop = stack.pop()

                if pop == '(':
                    if letter != ')':
                        no = -1  # print("no")
                        break
                else:
                    if letter != ']':
                        no = -1  # print("no")
                        break
    # if the string is not balanced
    if no == -1:
        print("no")
    else:
        # if the stack is empty
        if len(stack) == 0:
            print("yes")
        else:
            print("no")
