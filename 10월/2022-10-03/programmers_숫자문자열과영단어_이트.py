number = {'zero': 0,
          'one': 1,
          'two': 2,
          'three': 3,
          'four': 4,
          'five': 5,
          'six': 6,
          'seven': 7,
          'eight': 8,
          'nine': 9}

def solution(s):
    for num in number:
        if num in s:
            s = s.replace(num, str(number[num]))
    return int(s)