n = int(input())

for j in range(n):
    lst = input()

    count_score = 0
    count_O = 1
    for i in range(len(lst)):
        if(lst[i]=='O'):
            count_score+= count_O
            count_O += 1
        else:
            count_O = 1

    print(count_score)