import re

def solution(new_id):
    answer = ''
    
    new_id = re.sub('[^a-z0-9\.\-\_]', '', new_id.lower())
    new_id = re.sub('\.\.+', '.', new_id)
    new_id = re.sub('^\.|\.$', '', new_id)

    if new_id == '':
          new_id += 'a'

    new_id = re.sub('\.$', '', new_id[0:15])

    while len(new_id) < 3:
         new_id += new_id[-1]
    
    answer = new_id
    
    return answer