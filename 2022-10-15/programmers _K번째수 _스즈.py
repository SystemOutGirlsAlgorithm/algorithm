
'''
i번째 숫자부터 j번째 숫자까지 자르고 정렬
그 다음 k번째에 있는 수를 구하려고 함
array, [i,j,k]

slicing : 리스트나 문자열에서 값을 여러개 가져오는 기능
list[시작:끝] -> 시작은 포함, 끝 값은 포함 X

예제

array = [1,5,2,6,3,7,4]
commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]

    # commands의 길이 만큼 =3
    for i in range(len(commands)):
        # commands[i][0]-1:commands[i][1]
        # [5,2,6,3] -> 2번째부터 5번까지 잘라야함 -> 그러나 인덱스는 0부터 시작.
        arr = array[commands[i][0]-1:commands[i][1]]
        # [2,3,5,6]
        arr.sort()
        # [5]
        answer.append(arr[commands[i][2]-1])

'''

def solution(array, commands):
    answer = []
    for i in range(len(commands)):
        arr = array[commands[i][0]-1:commands[i][1]]
        arr.sort()
        answer.append(arr[commands[i][2]-1])
    return answer