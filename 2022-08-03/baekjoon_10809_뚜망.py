al = [-1] * 26
word = input()
for w in word:
    al[ord(w)-97] = word.index(w)
print(*al)