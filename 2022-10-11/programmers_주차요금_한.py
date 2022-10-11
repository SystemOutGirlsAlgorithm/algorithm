def calc(time1, time2):
    t1 = list(map(int, time1.split(':')))
    t2 = list(map(int, time2.split(':')))
    tsum = (t2[0] - t1[0]) * 60 + t2[1] - t1[1]
    return tsum

def solution(fees, records):
    answer = []
    cars = dict()
    times = dict()
    cmds = []
    
    for re in records:
        cmds.append(re.split())
    
    for c in cmds:
        if c[2] == 'IN':
            cars[c[1]] = c[0]
        else:
            if c[1] in times:
                times[c[1]] += calc(cars.pop(c[1]), c[0])
            else:
                times[c[1]] = calc(cars.pop(c[1]), c[0])
            
    for c in cars.keys():
        if c in times:
            times[c] += calc(cars[c], "23:59")
        else:
            times[c] = calc(cars[c], "23:59")
    
    for k in sorted(times):
        fee = fees[1]
        
        if times[k] >= fees[0]:
            times[k] -= fees[0]
            fee += times[k] // fees[2] * fees[3]
            if times[k] % fees[2] > 0:
                fee += fees[3]
        
        answer.append(fee)           
            
    return answer