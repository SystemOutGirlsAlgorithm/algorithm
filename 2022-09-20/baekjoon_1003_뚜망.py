cnt_0 = [0] * 41
cnt_1 = [0] * 41
cnt_0[0] = cnt_1[1] = 1

for i in range(2, 41):
    cnt_0[i] = cnt_0[i-1] + cnt_0[i-2]
    cnt_1[i] = cnt_1[i-1] + cnt_1[i-2]

T = int(input())
for _ in range(T):
    n = int(input())
    print(cnt_0[n], cnt_1[n])