def rank(win):
    if win == 6:
        return 1
    elif win == 5:
        return 2
    elif win == 4:
        return 3
    elif win == 3:
        return 4
    elif win == 2:
        return 5
    else: return 6


def solution(lottos, win_nums):
    win = 0
    blank = lottos.count(0)
    answer = []

    for i in lottos:
        for j in win_nums:
            if i == j:
                win += 1
    
    answer.append(rank(win+blank))
    answer.append(rank(win))

    return answer



print(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]	))