def solution(survey, choices):
    answer = ''
    score = {}
    score['AN'] = 0; score['NA'] = 0; score['CF'] = 0; score['FC'] = 0; score['JM'] = 0; score['MJ'] = 0; score['RT'] = 0; score['TR'] = 0

    for num in range(len(survey)):
      score[survey[num]] += 4-choices[num]

    if score['RT'] >= score['TR']: answer += 'R'
    else: answer += 'T'

    if score['CF'] >= score['FC']: answer += 'C'
    else: answer += 'F'
      
    if score['JM'] >= score['MJ']: answer += 'J'
    else: answer += 'M'

    if score['AN'] >= score['NA']: answer += 'A'
    else: answer += 'N'

      
    return answer
