def solution(numbers, hand):
    answer = ''
    left, right = [3, 0], [3, 2]
    phone = [[3, 1]]
    for i in range(3) :
        for j in range(3) :
            phone.append([i, j])
    for n in numbers :
        letter = ''
        if n not in [2, 5, 8, 0] :
            letter = 'L' if n in [1, 4, 7] else 'R'
        else :
            tmp_l = abs(phone[n][0] - left[0]) + abs(phone[n][1] - left[1])
            tmp_r = abs(phone[n][0] - right[0]) + abs(phone[n][1] - right[1])
            if tmp_l == tmp_r :
                letter = hand[0].upper()
            else :
                letter = 'L' if tmp_l < tmp_r else 'R'
        answer += letter
        if letter == 'L' :
            left = phone[n]
        else : 
            right = phone[n]
    return answer