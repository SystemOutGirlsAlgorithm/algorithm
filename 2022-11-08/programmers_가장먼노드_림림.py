# BFS(너비우선탐색) 공부 필요!
# deque는 앞과 뒤에서 데이터를 처리할 수 있는 양방향 자료형
from collections import deque
def solution(n, edge):
    graph = [[] for i in range(n+1)] # 각 노드에 연결된 노드 정보 저장
    route = [0]*(n+1) # 노드 1부터 각 노드까지의 거리
    edge.sort() # 노드 1부터 연결 정보 확인하기 위해 정렬
    queue = deque()
    answer = 0
    # 연결된 노드 정보 추가
    for e in edge:
        graph[e[0]].append(e[1]) # append(리스트에 마지막 요소 추가)
        graph[e[1]].append(e[0])
    # 출발
    queue.append(1)
    route[1] = 1
    
    # BFS
    while queue:
        now = queue.popleft() # 현재 노드
        # 현재 노드에서 방문할 수 있는 모든 노드 확인
        for g in graph[now]:
            # 아직 방문안했다면 큐에 추가
            if route[g] == 0:
                queue.append(g)
                # 최단거리 갱신
                route[g] = route[now]+1
    
    # 1번 노드로부터 가장 멀리 떨어진 노드 개수 계산
    max_edge = max(route)
    for r in route:
        if r == max_edge:
            answer += 1
    
    return answer