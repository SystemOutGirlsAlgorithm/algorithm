string = input()

save = []

def solution(brk1, brk2, num) :
    if len(save) == 0 :
        print(0)
        exit(0)
    count = 0
    while save :
        pop = save.pop()
        if pop == brk1 :
            if count == 0 :
                save.append(num)
            else :
                save.append(num*count)
            break
        elif pop == brk2 :
            print(0)
            exit(0)
        else :
            count += pop

for st in string :
    if st == ')' :
        solution('(', '[', 2)
    elif st == ']' :
        solution('[', '(', 3)
    else :
        save.append(st)

for s in save :
    if s == '(' or s == '[' :
        print(0)
        exit(0)
print(sum(save))