def solution(board, moves):
    answer = 0
    temp = []
    for m in moves :
        for i in range(len(board)) :
            if board[i][m-1] == 0 :
                continue
            if len(temp) > 0 and temp[-1] == board[i][m-1]:
                temp.pop()
                answer += 2
            else :
                temp.append(board[i][m-1])
            board[i][m-1] = 0
            break
    return answer