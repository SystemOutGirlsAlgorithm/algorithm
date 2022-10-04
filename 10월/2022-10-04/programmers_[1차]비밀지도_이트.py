def solution(n, arr1, arr2):
    answer = ['' for i in range(n)]

    for i in range(n):
        for _ in range(n):
            tmp1 = arr1[i] % 2
            arr1[i] /= 2

            tmp2 = arr2[i] % 2
            arr2[i] /= 2

            answer[i] += str(int(tmp1) | int(tmp2))

        answer[i] = answer[i][::-1]
        answer[i] = answer[i].replace('1', '#')
        answer[i] = answer[i].replace('0', ' ')

    return answer