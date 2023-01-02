import Foundation

/*
 미로 탐색
 1: 이동 가능 칸, 0: 이동 불가 칸
 (1, 1)에서 출발해 (N, M)의 위치로 이동. 인접 칸(상하좌우)
 지나야하는 최소 칸 수 구하기 (시작, 도착 칸 포함)
 */

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = input[0]
let M = input[1]
var miro = [[Int]]()
let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
for _ in 0..<N {
    miro.append(readLine()!.map{ Int(String($0))! })
}
print(BFS(0, 0))

func BFS(_ a: Int, _ b: Int) -> Int {
    var queue = [(a, b)]
    
    while !queue.isEmpty {
        let (x, y) = queue.first!
        queue.removeFirst()
        
        for i in 0..<4 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            
            guard dx >= 0 && dx < N && dy >= 0 && dy < M else { continue }
            if miro[dx][dy] == 1 {
                miro[dx][dy] = miro[x][y] + 1
                queue.append((dx, dy))
            }
        }
    }
    
    return miro[N-1][M-1]
}
