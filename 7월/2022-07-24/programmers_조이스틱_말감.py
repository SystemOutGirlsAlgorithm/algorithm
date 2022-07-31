def solution(name):
    answer = 0
    move = len(name) - 1
    for n in name :
        answer += min(ord('Z') - ord(n) + 1, ord(n)-ord('A'))
    if 'A' in name :
        for i, n in enumerate(name) :
            idx = i + 1
            while idx < len(name) and name[idx] == 'A' :
                idx += 1
            move = min(move, i * 2 + len(name) - idx, i + (len(name) - idx) * 2)     
    return answer + move