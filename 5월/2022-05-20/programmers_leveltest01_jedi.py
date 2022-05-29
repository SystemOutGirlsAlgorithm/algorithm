def solution01(s):
    if len(s) % 2 == 0:
        return(s[len(s)//2-1:len(s)//2+1])
    else:
        return(s[len(s)//2])

def solution02(s):
    answer = ""
    sm = s.split(" ")

    for i in sm:
        for j in range(len(i)):
            if j % 2 == 0:
                answer += i[j].upper()
            else:
                answer += i[j].lower()
        answer+= ' '
    answer = answer[:-1]
    return answer