import Foundation

/*
 A번 참가자는 B번 참가자와 몇 번째 라운드에서 만나게 될까?
 서로 만나게 되기 전까지는 항상 이긴다
 */

func solution(_ n:Int, _ a:Int, _ b:Int) -> Int {
    var answer = 0
    var A = a
    var B = b
    repeat {
        A = (A + 1) / 2
        B = (B + 1) / 2
        answer += 1
    } while A != B
    return answer
}

print(solution(8, 7, 4))
