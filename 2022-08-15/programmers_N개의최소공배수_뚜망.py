def gcd(M, m):
    if not m:
        return M
    return gcd(m, M % m)

def lcd(n1, n2, re):
    return n1 * n2 // re

def solution(arr):
    result = arr[0]
    for i in range(1, len(arr)):
        result = lcd(arr[i], result, gcd(result, arr[i]))
    
    return result
