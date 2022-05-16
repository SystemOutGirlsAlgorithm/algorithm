n = int(input())

for i in range(n):
    lst = [int(x) for x in input().split()]
    avg = (sum(lst)-lst[0])/lst[0]
    count = 0
    for j in range(1,len(lst)):
        if(lst[j] > avg):
            count+=1
    result = (count/lst[0])*100
    #print(str(result) + "%")
    #print("{}{}".format(result,"%"))
    print(f'{result:.3f}%')    