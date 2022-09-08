n, k = map(int, input().split())
kit = list(map(lambda x : int(x) - k, input().split()))
cnt, visited =  0, [0] * n

def bT(sumV):
    global cnt
    if sumV < 0:
        return

    if all(visited) and sumV >= 0:
        cnt += 1

    for i in range(n):
        if visited[i] == 0:
            visited[i] = 1
            bT(sumV + kit[i])
            visited[i] = 0

bT(0)
print(cnt)