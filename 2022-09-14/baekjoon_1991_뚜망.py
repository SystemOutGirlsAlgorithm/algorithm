N = int(input())
al = [0] * N
c1 = [0] * N
c2 = [0] * N

for i in range(N):
    al[i], c1[i], c2[i] = input().split()

def pre(s):
    if s.isalpha():
        print(s, end='')
        pre(c1[al.index(s)])
        pre(c2[al.index(s)])

def inorder(s):
    if s.isalpha():
        inorder(c1[al.index(s)])
        print(s, end='')
        inorder(c2[al.index(s)])

def post(s):
    if s.isalpha():
        post(c1[al.index(s)])
        post(c2[al.index(s)])
        print(s, end='')

pre('A')
print()
inorder('A')
print()
post('A')
