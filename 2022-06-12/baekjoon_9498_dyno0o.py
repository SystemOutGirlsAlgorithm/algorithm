def score(s):
  if (s>=0 and s<=100):
    if (90 <= s <= 100):
      print('A')
    elif (80 <= s <= 89):
      print('B')
    elif (70 <= s <= 79):
      print('C')
    elif (60 <= s <= 69):
      print('D')
    else:
      print('F')

a = int(input())
score(a)
