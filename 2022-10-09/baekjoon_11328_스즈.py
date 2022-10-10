import sys

n = int(input())
for i in range(n):
    first,second = map(str,sys.stdin.readline().split())
    # 애너그램 만드는 법
    '''
    s = acbd
    s_sort = sorted(s) -> ['a','b','c','d']
    s_sort2 = ''.join(sorted(s)) -> "abcd"    
    
    '''
    sf  = ''.join(sorted(first))
    ss = ''.join(sorted(second))

    if sf == ss :
        print("Possible")
    else:
        print("Impossible")
