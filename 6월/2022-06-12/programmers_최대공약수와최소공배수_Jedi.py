import math

def lcm(a,b):
      return (a * b) // math.gcd(a,b)

def solution(n, m):
    answer = []
    
    answer.append(math.gcd(n,m))
    answer.append(lcm(n,m))
    
    return answer