def delete_dot(new_id) :
    while new_id and (new_id[0] == '.' or new_id[-1] == '.') :
        if new_id and new_id[0] == '.' :
            new_id = new_id[1:]
        if new_id and new_id[-1] == '.' :
            new_id = new_id[:-1]
    return new_id

def solution(new_id):
    # 1단계 : 대문자 -> 소문자
    new_id = new_id.lower()
    # 2단계 : 다른 특수문자 제거
    temp = ''
    for id in new_id :
        if id not in '~!@#$%^&*()=+[{]}:?,<>/' :
            if temp and id == '.' and temp[-1] == '.' :
                continue
            temp += id         
    # 3, 4단계 : . 지우기
    new_id = delete_dot(temp)
    # 5단계 : 빈 문자열일 경우
    if new_id == '' :
        new_id = 'a'
    # 6단계 : 16자 이상일 경우
    if len(new_id) > 15 :
        new_id = new_id[:15]
    # 6단계 : 마침표가 있을 경우
    new_id = delete_dot(new_id)
    # 7단계 : 2자 이하일 경우
    if len(new_id) < 3 :
        while len(new_id) < 3 :
            new_id += new_id[-1]
    return new_id