answer = -1

def explore(p, cur, dungeons, visited):
    global answer
    answer = max(sum(visited), answer)
    for i in range(len(dungeons)):
        if visited[i] == 0 and dungeons[i][0] <= p:
            visited[i] = 1
            explore(p - dungeons[i][1], i + 1, dungeons, visited)
            visited[i] = 0

def solution(k, dungeons):
    visited = [0] * len(dungeons)
    explore(k, 0, dungeons, visited)
    return answer

