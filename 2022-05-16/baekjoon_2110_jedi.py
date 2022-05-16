<<<<<<< HEAD
import sys
input = sys.stdin.readline

n, c = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(int(input()))

arr.sort()

end = arr[-1] - arr[0]
start = 1
ans = 0

while start <= end:
    mid = (start + end) // 2
    count = 1
    current_router = arr[0]
    tmp = float("INF")

    for i in range(1, n):
        if current_router + mid <= arr[i]:
            tmp = min(arr[i] - current_router, tmp)
            count += 1
            current_router = arr[i]

    if count < c: # 공유기 설치를 더 해야함 -> 간격을 짧게 해야 함
        end = mid - 1

    elif count >= c: # 공유기 설치가 완료 or 더 많이 됨 -> 간격 늘려야 함
        start = mid + 1
        ans = max(ans, tmp)
    

print(ans)
=======
#baekjoon_2110_jedi
#binary search

n, c = map(int, input().split())

array = []
for i in range(n):
    array.append(int(input()))

array.sort()


def binary_search(array, start, end):
    while start <= end:
        mid = (start + end) // 2
        current = array[0]
        count = 1

        for i in range(1, len(array)):
            if array[i] >= current + mid:
                count += 1
                current = array[i]

        if count >= c:
            global answer
            start = mid + 1
            answer = mid
        else:
            end = mid - 1


start = 1
end = array[-1] - array[0]
answer = 0

binary_search(array, start, end)
print(answer)
>>>>>>> 9450005937666a24261dbf7e7ea401d50acbde02
