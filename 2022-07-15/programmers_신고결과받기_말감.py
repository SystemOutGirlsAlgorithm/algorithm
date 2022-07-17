def solution(id_list, report, k):
    id_bad = {}
    id_mail = {}
    answer = {}
    for id in id_list :  # 1
        id_bad[id] = 0
        id_mail[id] = []
        answer[id] = 0
    for re in report :   
        a = re.split(' ')[0]
        b = re.split(' ')[1]
        if b not in id_mail[a] :
            id_bad[b] += 1  # 2 
            id_mail[a].append(b)  # 3
    for key, val in id_bad.items() :  # 4
        if val < k :
            continue
        for m_key, m_val in id_mail.items() :
            if key in m_val :
                answer[m_key] += 1
    return list(answer.values())

# 개선 코드
# def solution(id_list, report, k):
#     id_bad = {id : 0 for id in id_list} # 1
#     answer = [0] * len(id_list)  # 2
#     for re in set(report) :    # 3
#         id_bad[re.split(' ')[1]] += 1  # 4
#     for re in set(report) :  # 5
#         if id_bad[re.split(' ')[1]] >= k :  # 6
#             answer[id_list.index(re.split(' ')[0])] += 1
#     return answer