def solution(phone_book):
    hash = {}
    for p in phone_book :
        hash[p] = 0
    for phone in phone_book :
        for p in range(1, len(phone)) :
            if phone[:p] in hash :
                return False
    return True