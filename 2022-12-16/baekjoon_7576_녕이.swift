import Foundation

/*
 토마토
 보관 후 하루가 지나면, 익은 토마토들의 인접(상하좌우)한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
 며칠이 지나면 토마토 들이 모두 익게 되는지, 최소 일수를 알고 싶다.
 익은 토마토: 1, 안익은 토마토: 0, 토마토 없음: -1
 모두 익지 못하는 상황 -1 출력
 */

func BFS() {
    var front = 0
    while queue.count > front {
        let (x, y) = queue[front] //removeFirst() -> 시간초과
        front += 1 //인덱스를 사용해서 배열 내 원소를 삭제하지 않는 방식으로 진행
        
        for i in 0..<4 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            
            guard (0..<N) ~= dx, (0..<M) ~= dy else { continue }
            if box[dx][dy] == 0 {
                box[dx][dy] = box[x][y] + 1
                queue.append((dx, dy))
            }
        }
    }
}

let input = readLine()!.split(separator: " ").map{ Int(String($0))!}
let M = input[0]
let N = input[1]
var answer = 0
var box = [[Int]]()
var queue = [(Int, Int)]() //tuple
let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
for _ in 0..<N {
    box.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}

for i in 0..<N {
    for j in 0..<M {
        if box[i][j] == 1 {
            queue.append((i, j))
        }
    }
}

BFS()
for i in 0..<N {
    if box[i].contains(0){
        answer = 0
        break
    }
    answer = max(answer, box[i].max()!)
}
print(answer - 1)
