def solution(number, k):
    if k == len(number) - 1 :
        num = list(number)
        return max(num)
    if k == 1 :
        num = list(number)
        num.remove(min(num))
        return ''.join(num)
    answer = []
    for n in number :
        if len(answer) == 0 :
            answer.append(n)
            continue
        while True :
            if k == 0 or len(answer) == 0:
                break
            if answer[-1] < n :
                answer.pop()
                k-=1
            else :
                break
        answer.append(n)
    return ''.join(answer)