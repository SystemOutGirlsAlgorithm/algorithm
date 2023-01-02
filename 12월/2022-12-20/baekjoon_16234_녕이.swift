import Foundation

/*
 NxN 크기의 땅, 인구 이동 == 하루
 - 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면 국경선을 하루동안 연다
 - 국경선이 모두 열렸다면 인구 이동 시작
 - 인접칸만 이동 가능, 그 나라들은 하루 동안 연합
 - 연합인 나라의 칸 인구수는 연합인구수/연합국수
 - 연합 해제, 국경선 닫기
 인구 이동 며칠 동안 발생? -> 모든 국경선이 열리지 않을 때까지 반복!
 */

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let n = input[0]
let l = input[1]
let r = input[2]
let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
var array = [[Int]]()
var isMoving = false
var answer = 0

for _ in 0..<n {
    array.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}

func BFS(_ i: Int, _ j: Int, _ visited: inout [[Bool]]) {
    var queue = [(i, j)]
    var front = 0
    var country = [(i, j)]
    var count = 1
    var sum = array[i][j]
    visited[i][j] = true
    
    //쭉 돌면서 국경선 열기
    while queue.count > front {
        let (x, y) = queue[front]
        front += 1
        
        for i in 0..<4 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            
            guard (0..<n) ~= dx, (0..<n) ~= dy else { continue }
            guard !visited[dx][dy] else { continue }
            
            if (l...r) ~= abs(array[x][y] - array[dx][dy]) {
                visited[dx][dy] = true
                sum += array[dx][dy]
                count += 1
                country.append((dx, dy))
                queue.append((dx, dy))
            }
        }
    }
    //인구 이동!
    if count > 1 {
        let avg = sum / count
        for i in 0..<country.count {
            let (x, y) = country[i]
            array[x][y] = avg
        }
        isMoving = true
    }
}

while true {
    var visited = [[Bool]](repeating: [Bool](repeating: false, count: n), count: n)
    isMoving = false
    
    for i in 0..<n {
        for j in 0..<n {
            if !visited[i][j] {
                BFS(i, j, &visited)
            }
        }
    }
    if isMoving {
        answer += 1
    } else {
        break
    }
}
print(answer)
