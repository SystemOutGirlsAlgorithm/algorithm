from collections import deque

def solution(bridge_length, weight, truck_weights):
    bridge = deque([0] * bridge_length)
    add = 0
    end = deque()
    truck = deque(truck_weights)
    time = 0
    while len(end) != len(truck_weights) : 
        b = bridge.popleft()
        add -= b
        if b > 0 :
            end.append(b)
        if not truck or add + truck[0] > weight :
            bridge.append(0)
        else :
            t = truck.popleft()
            add += t
            bridge.append(t)
        time += 1
    return time