import Foundation

/*
 NxN 그리드에 R, G, B (적록색약 -> 빨==초)
 구역 == 같은 색상, 상하좌우 인접
 적록색약인 사람, 아닌 사람이 본 구역 수
 */

func BFS(_ i: Int, _ j: Int){
    var queue = [(i, j)]
    visited[i][j] = true
    var front = 0
    
    while queue.count > front {
        let (x, y) = queue[front]
        front += 1
        
        for i in 0..<4 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            
            guard (0..<N) ~= dx, (0..<N) ~= dy else {
                continue
            }
            if visited[dx][dy] || array[x][y] != array[dx][dy] { //방문한 곳이거나 색상이 다르면
                continue
            }
            visited[dx][dy] = true
            queue.append((dx, dy))
        }
    }
}


// input
let N = Int(readLine()!)!
var array = [[String]]()
for _ in 0..<N {
    array.append(readLine()!.map{ String($0) })
}

let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
var visited = [[Bool]](repeating: [Bool](repeating: false, count: N), count: N)
var count = 0
//적록색약이 아닌 사람
for i in 0..<N {
    for j in 0..<N {
        if !visited[i][j] { //방문한 곳 --> 아직 그림이 아닌 곳
            count += 1
            BFS(i, j)
        }
    }
}
print(count, terminator: " ")
count = 0

//적록색약인 사람
for i in 0..<N {
    for j in 0..<N {
        if array[i][j] == "R" {
            array[i][j] = "G"
        }
    }
}
visited = [[Bool]](repeating: [Bool](repeating: false, count: N), count: N) //초기화
for i in 0..<N {
    for j in 0..<N {
        if !visited[i][j] {
            count += 1
            BFS(i, j)
        }
    }
}
print(count)
