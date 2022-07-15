def check_letter(begin, check) :
    diff = 0
    for i in range(len(begin)) :
        if begin[i] != check[i] :
            diff += 1
    if diff == 1 :
        return True
    return False

def dfs(begin, target, words, visit, answer) :
    if begin == target :
        answer.append(len(visit))
        return
    for i in range(len(words)) :
        if check_letter(begin, words[i]) :
            if words[i] not in visit :
                visit.append(words[i])
                dfs(words[i], target, words, visit, answer)
                visit.remove(words[i])
    
def solution(begin, target, words):
    if target not in words :
        return 0
    answer = []
    visit = []
    dfs(begin, target, words, visit, answer)
    return min(answer)