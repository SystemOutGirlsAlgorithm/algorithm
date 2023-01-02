import Foundation

/*
 자연수 n
 1. n의 다음 큰 숫자는 n보다 큰 자연수
 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때, 1의 개수가 같다
 3. n의 다음 큰 숫자는 조건 1, 2를 만족하는 수 중 가장 작은 수
 */

func solution(_ n:Int) -> Int{
    var next = n + 1
    while true {
        let binaryN = String(n, radix: 2)
        let binaryNext = String(next, radix: 2)
        if binaryN.filter({ $0 == "1" }).count == binaryNext.filter({ $0 == "1" }).count {
            break
        }
        next += 1
    }
    return next
}

print(solution(78))
