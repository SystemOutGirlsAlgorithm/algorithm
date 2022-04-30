import sys
input = sys.stdin.readline

l, r = map(str, input().split())

def solution(l, r) :
    count = 0
    # L과 R의 자리 수가 다르면 0 출력
    if len(l) != len(r) :
        print(count)
        return
    # L과 R의 자리 수가 같을 때
    # L과 R의 맨 앞자리 수가 같을 때
    if l[0] == r[0] :
        i = 1
        # 맨 앞자리 수가 8일 때
        if l[0] == '8' and r[0] == '8' :
            count += 1
        while i < len(l) and l[i] == r[i]:
            if l[i] == '8' and r[i] == '8' :
                count += 1
            i += 1
            if i >= len(l) :
                break
    print(count)
    return 

solution(l, r)