def solution(s):
    answer = s[0].upper()
    for i in range(1, len(s)):
        if answer[i - 1] == ' ' and s[i].isalpha():
            answer += s[i].upper()
        else:
            answer += s[i].lower()
    return answer

