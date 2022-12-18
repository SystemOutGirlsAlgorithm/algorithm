import Foundation

/*
 이동하려는 칸이 주어지고, 몇 번 움직이면 이 칸으로 이동할 수 있을까?
 */

func BFS(_ i:Int, _ j:Int, size I: Int, destinationX: Int, destinationY: Int) {
    var visited = [[Int]](repeating: [Int](repeating: 0, count: 301), count: 301)
    var queue = [(i, j)]
    var front = 0
    
    while queue.count > front {
        let (x, y) = queue[front]
        front += 1
        
        if x == destinationX, y == destinationY {
            print(visited[x][y])
            return
        }
        
        for i in 0..<8 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            guard (0..<I) ~= dx, (0..<I) ~= dy else { continue }
            if visited[dx][dy] != 0 { continue }
            visited[dx][dy] = visited[x][y] + 1
            queue.append((dx, dy))
        }
    }
}

let T = Int(readLine()!)!
let direction = [[-2, 1], [-1, 2], [1, 2], [2, 1], [2, -1], [1, -2], [-1, -2], [-2, -1]]

for _ in 0..<T {
    let I = Int(readLine()!)!
    let currentPosition = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let destination = readLine()!.split(separator: " ").map{ Int(String($0))! }
    BFS(currentPosition[0], currentPosition[1], size: I, destinationX: destination[0], destinationY: destination[1])
}
