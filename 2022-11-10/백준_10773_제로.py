T = int(input());
numList = [];
for tc in range(1, T + 1):
  newNum = int(input());
  if newNum == 0:
    numList.pop();
  else:
    numList.append(newNum);
print(sum(numList));
