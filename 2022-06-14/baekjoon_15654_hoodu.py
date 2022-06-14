import sys
input = sys.stdin.readline


# 백트레킹
def backtracking():
    # M과 길이가 같아지면 출력해줌
    if len(l) == M:
        print(' '.join(list(map(str,l))))
    
    else:
        for number in k:
            # 배열 k를 순회하며 새로운 배열 l 안에 값이 있는지 확인
            # 없다면 넣어주고 재귀를 통해 다시 검사한다.
            if number not in l:
                l.append(number)
                backtracking()
                l.pop()


N, M = map(int,input().split())
k = sorted(list(map(int,input().split())))
l = []
backtracking()
