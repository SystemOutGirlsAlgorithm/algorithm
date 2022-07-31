def solution(id_list, report, k):
    answer = []
    declaration_count = {}
    claim_list = {}

    for id in id_list:
        declaration_count[id] = 0
        claim_list[id] = []

    for claim in report:
        h1, h2 = claim.split(' ')
        if not h2 in claim_list[h1]:
            claim_list[h1].append(h2)
            declaration_count[h2] += 1

    for member in claim_list:
        alert = 0
        for member_dec in claim_list[member]:
            if declaration_count[member_dec] >= k:
                alert += 1
    
        answer.append(alert)

    return answer