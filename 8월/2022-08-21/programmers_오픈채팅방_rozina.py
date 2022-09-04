def solution(record):
    answer = []
    ids = {}
    for rec in record:
        if rec.split(' ')[0] == 'Leave': pass
        else: ids[rec.split(' ')[1]] = rec.split(' ')[2]
        
    for rec in record:
        name = ids[rec.split(' ')[1]]
        if rec.split(' ')[0] == 'Enter':
            
            answer.append(f'{name}님이 들어왔습니다.')
        elif rec.split(' ')[0] == 'Leave':
            answer.append(f'{name}님이 나갔습니다.')
        else: pass
    
    return answer
