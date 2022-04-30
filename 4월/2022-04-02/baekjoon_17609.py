import sys
input = sys.stdin.readline

t = int(input().rstrip('\n'))

def secondloop(left, right, string) :
    while left < right :
        if string[left] == string[right] :
            left += 1
            right -= 1
        else :
            return False
    return True

def firstloop(left, right, string) :
    while left < right :
        if string[left] == string[right] :
            left += 1
            right -= 1
        else :
            check1 = secondloop(left+1, right, string)
            check2 = secondloop(left, right-1, string)
            
            if check1 or check2 :
                return 1
            else :
                return 2
    return 0

for _ in range(t) :
    string = list(input().rstrip('\n'))
    left = 0
    right = len(string) -1
    answer = firstloop(left, right, string)
    print(answer)