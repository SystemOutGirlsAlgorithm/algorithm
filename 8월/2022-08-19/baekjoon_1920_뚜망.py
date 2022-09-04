# 이진탐색
def binarySearch(arr, N, k):
    start = 0
    end = N - 1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == k:
            return 1
        elif arr[mid] > k:
            end = mid - 1
        else:
            start = mid + 1
    return 0

N = int(input())
arr = list(map(int, input().split()))
arr.sort()
M = int(input())
data = list(map(int, input().split()))


for m in data:
    print(binarySearch(arr, N, m))

