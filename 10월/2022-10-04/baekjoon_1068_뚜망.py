"""
N - len(par) : 존재하는 모든 리프 노드의 개수
cnt : 제거될 노드의 아래에 존재하는 리프 노드의 개수
"""
def leaf(l):
    # 루트노드면 바로 함수 종료 -> 더 탐색할 수 없으므로
    while l != -1:
        # 리프 노드의 조상 노드에 n이 있으면 return 1 (cnt += 1)
        if l == n:
            return 1
        l = tree[l]
    return 0

N = int(input())
tree = list(map(int, input().split()))
n = int(input())
par = set(tree) - {-1}

# 사라져야 하는 n이 부모노드의 유일한 자식노드인 경우 그 부모노드가 리프노드가 되어야 하기 때문에 무조건 +1
# cnt를 결과값에서 빼줄 거기 때문에 +1을 하려면 -1로 초기값을 해야 함
if tree[n] != -1 and tree.count(tree[n]) == 1:
    cnt = -1
else:
    cnt = 0

for i in range(N):
    # 리프 노드들에 대해서만 탐색
    if i not in par:
        cnt += leaf(i)

print(N - len(par) - cnt)
