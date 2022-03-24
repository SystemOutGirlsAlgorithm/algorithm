n, m, b = map(int, input().split())

ground = []
# 땅의 높이를 받는데 굳이 2차원 배열로 할 필요가 없으므로 1차원 배열에 넣는다.
for _ in range(n) :
    ground += list(map(int, input().split()))
# 땅이 높은 부분부터 해야 인벤토리에 저장해서 낮은 땅에 블록을 올릴 수 있으므로 내림차순 정렬
ground = sorted(ground, reverse=True)

answer = []
# 현재 땅의 최소값부터 최대값까지
for i in range(min(ground), max(ground)+1) :
    time = 0
    inven = b
    chk = True
    for g in ground :
        # 땅의 높이가 같으면 넘김
        if g == i :
            continue
        # 기준보다 땅의 높이가 낮을 때
        elif i > g :
            # 땅의 높이 차이
            minus = i - g
            # 땅의 높이가 256 초과거나 인벤토리 내에 블록 개수가 음수면 안된다.
            if g + minus > 256 or inven - minus < 0 :
                chk = False
                break
            # 인벤토리에서 꺼내기
            inven -= minus
            # 작업 시간이 1초 걸리므로 그냥 minus
            time += minus
        # 기준보다 땅의 높이가 높을 때
        elif i < g :
            # 땅의 높이 차이
            minus = g - i
            # 땅의 높이가 0보다 작으면 안된다.
            if g - minus < 0 :
                chk = False
                break
            # 인벤토리에 넣기
            inven += minus
            # 작업 시간이 2초 걸리므로 *2
            time += 2*minus
    # 문제 없이 진행되면 배열에 넣기
    if chk == True :
        answer.append([time, i])
 
 
# 시간을 기준으로 오름차순 정렬한 후, 동일 시간 내 땅 높이를 내림차순으로 정렬
answer = sorted(answer, key=lambda x: (x[0], -x[1]))
print(answer[0][0], answer[0][1])