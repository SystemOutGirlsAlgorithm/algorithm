def solution(sizes):
    answer = 0
    
    for i in range(len(sizes)):
        tmp = 0
        if sizes[i][0] < sizes[i][1]:
            tmp = sizes[i][0]
            sizes[i][0] = sizes[i][1]
            sizes[i][1] = tmp
    
    height = 1
    weight = 1
    
    for i in range(len(sizes)):
        if height < sizes[i][0]:
            height = sizes[i][0]
        if weight < sizes[i][1]:
            weight = sizes[i][1]

    
    print(weight, height)
    
    answer = weight * height
    
    return answer