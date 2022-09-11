word = input()
alpha = ['c=','c-','dz=','d-','lj','nj','s=','z=']

for a in alpha:
    word = word.replace(a, '?')

print(len(word))