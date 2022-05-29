def solution(id_list, report, k):
    answer = [0] * len(id_list)
    reported = {}

    for rep in report:
        id1, id2 = rep.split(' ')
        if id2 not in reported:
            reported[id2] = list()
            reported[id2].append(id1)
        else:
            if id1 in reported[id2]:
                continue
            else:
                reported[id2].append(id1)
    
    for key in reported.keys():
        if len(reported[key]) >= k:
            for i in reported[key]:
                answer[id_list.index(i)] += 1

    return answer


print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"], 2))