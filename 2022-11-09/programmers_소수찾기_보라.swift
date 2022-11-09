import Foundation

//소수 찾기
func isPrime(_ n: Int) -> Bool {
    var i = 3
    if n < 4 {
        return n == 1 ? false :  true
    }
    if n % 2 == 0 {
        return false
    }
    
    while (i*i) <= n {
        if n % i == 0 {
            return false
        }
        i += 2
    }
    return true
}

func solution(_ n:Int) -> Int {
    //    var cnt = 0
    //    for i in 1 ... n {
    //        if isPrime(i) {
    //            cnt += 1
    //        }
    //    }
    
    //효율성 테스트로 추가
    var cnt = 1
    
    for i in 1 ... n where i % 2 != 0 {
        if isPrime(i) {
            cnt += 1
        }
        
    }
    return cnt
}

print(solution(5))
