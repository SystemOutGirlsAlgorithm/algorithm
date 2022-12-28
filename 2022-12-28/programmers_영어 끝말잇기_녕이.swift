import Foundation

/*
 배열 돌리기 NxM 배열. 연산을 R번 적용
 1번: 배열 상하 반전
 2번: 배열 좌우 반전
 3번: 오른쪽으로 90도 회전
 4번: 왼쪽으로 90도 회전
 N/2xM/2인 4개의 부분 배열로 나눠서
 5번:
 */

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var dropout = 1
    var count = 1
    var set = Set<String>()
    var last = words[0].first!
    var final = false
    for word in words {
        if set.contains(word) { //중복 글자의 경우
            final = true
            break
        }
        if word.first! == last { //끝말잇기가 이어진다면
            dropout += 1
            last = word.last! //마지막 글자
            set.insert(word)
        }else {
            final = true
            break
        }
        if dropout == n + 1 {
            count += 1
            dropout = 1
        }
    }
    if final == false {
        return [0,0]
    }
    return [dropout, count] //가장 먼저 탈락하는 사람, 자신의 몇 번째 차례에 탈락하는지
}

print(solution(3, ["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]))
print(solution(5, ["hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"]))
print(solution(2, ["hello", "one", "even", "never", "now", "world", "draw"]))
