def solution(array, commands):
    answer = []
    
    for com in commands:
        answer.append(sorted(array[com[0]-1:com[1]])[com[2]-1])
        
    return answer