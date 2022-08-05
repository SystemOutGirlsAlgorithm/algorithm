def solution(new_id):
    arr = ['-', '.', '_']
    new_id = new_id.lower()

    for i in new_id:
        if i.isalpha() or i.isdigit() or i in arr:
            continue
        else:
            new_id = new_id.replace(i,'')

    if '.' in new_id:
        for i in range(new_id.count('.'),1,-1):
            new_id = new_id.replace('.'*i, '.')

    new_id = new_id.strip('.')

    if new_id == '':
        new_id = 'aaa'
    elif len(new_id) >= 16:
        new_id = new_id[:15].strip('.')
    elif len(new_id) <= 2:
        new_id += new_id[-1]*(3-len(new_id))
    
    answer = new_id
    return answer