#baekjoon_2512_jedi.py
#binary

num = int(input())
req = list(map(int, input().split()))
bud = int(input())

start = 0
end = max(req)

while start <= end:
    mid = (start+end)//2
    arr = 0

    for i in req:
        if i <= mid:
            arr += i
        else:
            arr += mid

    if arr <= bud:
        start = mid + 1
    else:
        end = mid - 1

print(end)



