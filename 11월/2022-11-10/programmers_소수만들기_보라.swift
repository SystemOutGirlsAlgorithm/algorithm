import Foundation

func isPrime(_ n: Int) -> Bool {
    var i = 3
    if n < 4 {
        return n == 1 ? false : true
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
func solution(_ nums:[Int]) -> Int {
    var answer = 0
    
    for i in 0 ..< nums.count {
        for j in (i+1) ..< nums.count {
            for k in (j+1) ..< nums.count {
                if isPrime(nums[i]+nums[j]+nums[k]) {
                    answer += 1
                }
            }
        }
    }

    return answer
}
