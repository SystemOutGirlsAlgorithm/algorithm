import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t) :
  n = int(input())
  tree = list(map(int, input().split()))
  # 오름차순으로 정렬
  tree.sort()
  
  height = [0] * n
  
  # 인접한 두 통나무 간의 높이의 차가 작아야하므로 정렬한 수를 지그재그로 넣는다.
  # 앞뒤앞뒤앞뒤... 순서로
  check = 0
  for i in range(len(tree)) :
    # 인덱스가 짝수일 때는 앞에 넣기
    if i % 2 == 0 :
      height[check] = tree[i]
      check += 1
    # 인덱스가 홀수일 때는 뒤에 넣기 
    else :
      chk = -1 * check
      height[chk] = tree[i]
  
  maxNum = 0
  for j in range(len(height)) :
    num = 0
    # 맨 뒤와 맨 앞도 인접해있으므로 값 비교
    if j > len(height)-2 :
      num = abs(height[j] - height[0])
    else :
      num = abs(height[j] - height[j+1])
    maxNum = max(maxNum, num)
  
  print(maxNum)