odd = ['1', '3', '5', '7', '9']
odd_list=[]
for _ in range(7):
    n = input()
    if n[-1] in odd:
        odd_list.append(int(n))
if odd_list == []:
    print(-1)
else:
    print(f'{sum(odd_list)}\n{min(odd_list)}')