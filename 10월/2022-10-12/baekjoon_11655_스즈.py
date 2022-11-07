sentence = input()
re_sentence = ""

for i in sentence:
    if i.islower():
        i = ord(i)+13
        if i>122:
            i-=26
        re_sentence+=chr(i)
    elif i.isupper():
        i = ord(i)+13
        if i>90:
            i-=26
        re_sentence+=chr(i)
    else:
        re_sentence+=i

print(re_sentence)