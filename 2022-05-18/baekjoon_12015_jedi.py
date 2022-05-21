#baekjoon_12015_jedi.py
#binary

num = 6 # int(input())
arrs = [10, 20, 10, 30, 20, 50]  # list(map(int, input().split()))

lis = [0]

for arr in arrs:
    if lis[-1] < arr:
        lis.append(arr)
    else:
        left = 0
        right = len(lis)

        while left < right:
            mid = (right+left) // 2
            if lis[mid] < arr:
                left = mid+1
            else:
                right = mid
        lis[right] = arr

print(len(lis)-1)