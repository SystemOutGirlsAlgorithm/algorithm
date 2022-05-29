#input 숫자 큰거에서작은걸로
N = int(input())
 
list=[]

for n in str(N):
  list.append(int(n))

list.sort(reverse=True)

for i in list:
  print(i, end='')