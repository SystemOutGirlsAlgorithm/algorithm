import Foundation

/*
 지렁이는 인접한 다른 배추로 이동할 수 있다. (인접 == 상하좌우)
 배추들이 몇 군데 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다.
 최소 배추흰지렁이 마리 수 구하기
 */

func BFS(_ i: Int, _ j: Int, _ N: Int, _ M: Int, _ array: inout [[Int]]) {
    var queue = [(Int, Int)]()
    queue.append((i, j))
    var front = 0
    while queue.count > front {
        let (x, y) = queue[front]
        front += 1
        for i in 0..<4 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            guard (0..<N) ~= dx, (0..<M) ~= dy else { continue }
            if array[dx][dy] == 1 {
                array[dx][dy] = 0
                queue.append((dx, dy))
            }
        }
    }
}

let T = Int(readLine()!)!
var queue = [(Int, Int)]()
let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
for _ in 0..<T {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let M = input[0]
    let N = input[1]
    let K = input[2]
    var answer = 0
    var array = [[Int]](repeating: [Int](repeating: 0, count: M), count: N)
    for _ in 0..<K {
        let xy = readLine()!.split(separator: " ").map{ Int(String($0))! }
        array[xy[1]][xy[0]] = 1
    }
    for i in 0..<N {
        for j in 0..<M {
            if array[i][j] == 1 {
                answer += 1
                BFS(i, j, N, M, &array)
            }
        }
    }
    print(answer)
}
