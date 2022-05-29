
answers = [1,2,3,4,5]

a = [1, 2, 3, 4, 5]
b = [2, 1, 2, 3, 2, 4, 2, 5]
c = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

count = [0,0,0]

for i in range(len(answers)):
    if a[i%5] == answers[i]:
        count[0] += 1
    if b[i%8] == answers[i]:
        count[1] += 1
    if c[i%10] == answers[i]:
        count[2] += 1

count_dict = {1: count[0], 2: count[1], 3: count[2]}
top = max(count_dict.values())
result = [student for student, score in count_dict.items() if score == top]

print(result)