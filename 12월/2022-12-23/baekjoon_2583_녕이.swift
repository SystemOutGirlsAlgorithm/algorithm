import Foundation

/*
 MxN, K개의 직사각형을 그린다.
 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
 몇개의 분리된 영역으로 나누어지는지, 분리된 영역의 넓이가 얼마인지
 */

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let m = input[0]
let n = input[1]
let k = input[2]
var array = [[Int]](repeating: [Int](repeating: 0, count: n), count: m)
for _ in 0..<k {
    let rectangle = readLine()!.split(separator: " ").map{ Int(String($0))! }
    for i in rectangle[1]..<rectangle[3] {
        for j in rectangle[0]..<rectangle[2] {
            array[i][j] = 1
        }
    }
}

var visited = [[Bool]](repeating: [Bool](repeating: false, count: n), count: m)
let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]

func BFS(_ i: Int, _ j: Int) -> Int {
    var queue = [(i, j)]
    var front = 0
    var count = 1
    array[i][j] = 1
    visited[i][j] = true
    
    while queue.count > front {
        let (x, y) = queue[front]
        front += 1
        
        for i in 0..<4 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            guard (0..<m) ~= dx, (0..<n) ~= dy else { continue }
            guard !visited[dx][dy], array[dx][dy] == 0 else { continue }
            visited[dx][dy] = true
            array[dx][dy] = 1
            count += 1
            queue.append((dx, dy))
        }
    }
    return count
}
var answer = [Int]()
for i in 0..<m {
    for j in 0..<n {
        if !visited[i][j], array[i][j] == 0 {
            answer.append(BFS(i, j))
        }
    }
}
print(answer.count)
answer.sorted().forEach {
    print($0, terminator: " ")
}
