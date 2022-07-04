import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    if scoville[0] == 0 and K > 0:
        return -1
    while scoville[0] < K :
        if len(scoville) == 1 :
            break
        min_first = heapq.heappop(scoville)
        min_second = heapq.heappop(scoville)
        mix = min_first + (min_second * 2)
        heapq.heappush(scoville, mix)
        answer += 1
    if scoville[0] < K :
        return -1
    return answer