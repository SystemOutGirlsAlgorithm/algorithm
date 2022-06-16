def solution(price, money, count):
    answer = -1
    
    charge = 0
    
    for i in range(1, count+1):
        charge += i*price
        
    if money < charge:
        answer = charge - money
    elif money >= charge:
        answer = 0
    

    return answer