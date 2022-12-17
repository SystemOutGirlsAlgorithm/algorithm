import sys
sys.stdin = open('input.txt')

T = int(input())

for tc in range(1, T+1):
    sentence = list(input().split())    # 띄어쓰기 기준으로 문장 나눔
    result = ''    # 단어를 뒤집은 문장

    for i in range(len(sentence)):    # 어절 갯수만큼 순회
        for j in range(1, len(sentence[i])+1):    # 단어 길이만큼 순회
            result += sentence[i][-j]
        result += ' '

    print(result)