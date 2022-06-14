import calendar

def solution(a, b):
    answer = ''
    
    num = calendar.weekday(2016, a, b)
    day = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']
    
    answer = day[num]
    
    return answer