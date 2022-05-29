
phone_number = '01033334444'

answer = ''

for i in range(len(phone_number) - 4):
    answer += '*'
    
answer += phone_number[len(phone_number) - 4:]

print(answer)