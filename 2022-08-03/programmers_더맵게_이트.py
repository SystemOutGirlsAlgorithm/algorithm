## https://school.programmers.co.kr/learn/courses/30/lessons/42626
## 함수화...

import heapq
def solution(scoville, k):
    heap = []
    for num in scoville:            # 일단 순차적으로 heap에 넣기
        heapq.heappush(heap, num)

    cnt = 0
    while heap[0] < k:              # 최소 힙이 k보다 같거나 클 때까지 
        try:                        # 섞은 음식의 스코빌 지수를 넣고, 가장 덜 매운 두 음식을 pop
            heapq.heappush(heap, heapq.heappop(heap) + heapq.heappop(heap) * 2)
        except IndexError:
            return -1               # 모든 음식의 스코빌 지수를 k 이상으로 만들 수 없다면 -1을 return
        cnt += 1

    return cnt 

solution([1,2,3,9,10,12], 7)