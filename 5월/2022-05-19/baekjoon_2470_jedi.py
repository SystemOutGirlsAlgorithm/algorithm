#baekjoon_2470_jedi.py
#binary

num = int(input())
arrs = list(map(int, input().split()))
arrs.sort()

start = 0
end = num-1

answer = (max(arrs)) + 1
final = []

while start < end:
    left = arrs[start]
    right = arrs[end]

    po = left + right

    if abs(po) < answer:
        answer = abs(po)
        final = [left, right]

    if po < 0:
        start += 1
    else:
        end -= 1

print(final[0], final[1])


# start = arrs[0]
# end = arrs[-1]
# target = 0

# while start < end:
#     mid = (start+end) // 2
#     for arr in arrs:
#         if arr + mid 

