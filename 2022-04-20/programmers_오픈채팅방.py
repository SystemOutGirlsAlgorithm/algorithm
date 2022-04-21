def solution(record):
    answer = []
    check = []
    userId = {}
    name = []
    for r in range(len(record)):
        c = record[r].split(' ')[0]
        u = record[r].split(' ')[1]
        if c != "Change" :
            if c == "Enter" :
                n = record[r].split(' ')[2]
                if u in userId :
                    for i in range(len(userId[u])) :
                        name[userId[u][i]] = n
            else :
                n = name[userId[u][0]]
        else :
            n = record[r].split(' ')[2]
            if u not in userId :
                userId[u] = [r]
            else :
                for i in range(len(userId[u])) :
                    name[userId[u][i]] = n
        
        name.append(n)
        check.append(c)
        try :
            tmp = userId[u]
            tmp.append(r)
            userId[u] = tmp
        except :
            userId[u] = [r]
            
    for i in range(len(check)) :
        if check[i] == "Change" :
            continue
        checkEnter = "들어왔습니다."
        if (check[i] == "Leave") :
            checkEnter = "나갔습니다."
        s = name[i] + "님이 " + checkEnter
        answer.append(s)
    return answer