def solution(nums):
    answer = 0
    
    num = len(nums) // 2
    
    arr = list(set(nums))
    if len(arr) > num:
        answer = num
    else:
        answer = len(arr)
            
    return answer