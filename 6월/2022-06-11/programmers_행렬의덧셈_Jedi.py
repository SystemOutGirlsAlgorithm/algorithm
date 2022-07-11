def solution(arr1, arr2):
    answer = arr1
    
    for i in range(len(arr1)):
        for j in range(len(arr1[i])):
            answer[i][j] = (arr1[i][j] + arr2[i][j])
    
    return answer