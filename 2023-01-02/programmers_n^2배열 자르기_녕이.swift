import Foundation

func solution(_ n:Int, _ left:Int64, _ right:Int64) -> [Int] {
    var answer = [Int]()
    let (startX, startY) = (left/Int64(n)+1, left%Int64(n)+1)
    let (endX, endY) = (right/Int64(n)+1, right%Int64(n)+1)

    var col = startY
    for row in startX...endX {
        while col <= n {
            answer.append(Int(max(row, col)))
            if row == endX, col == endY { break }
            col += 1
        }
        col = 1
    }
    return answer
    
    //answer = (left...right).map { max(Int($0) / n, Int($0) % n) + 1 } <- 더 간결한 코드...
}

print(solution(4, 7, 14))
