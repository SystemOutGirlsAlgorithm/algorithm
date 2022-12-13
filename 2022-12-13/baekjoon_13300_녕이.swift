import Foundation

/*
 성별끼리, 같은 학년끼리
 한방에 배정할 수 있는 최대 인원 수 K
 모든 학생을 배정하기 위해 필요한 방의 최소 개수 구하기
 */

var answer = 0
let nk = readLine()!.split(separator: " ").map{Int(String($0))!}
var student = Array(repeating: Array(repeating: 0, count: 7), count: 2)
for _ in 0..<nk[0] {
    let st = readLine()!.split(separator: " ").map{Int(String($0))!}
    student[st[0]][st[1]] += 1
}
for i in 0..<2 {
    for j in 1...6 {
        guard student[i][j] != 0 else { continue }
        answer += student[i][j] < nk[1] ? 1 : (student[i][j] - 1) / nk[1] + 1
    }
}
print(answer)
