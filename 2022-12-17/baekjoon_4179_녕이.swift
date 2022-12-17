import Foundation

/*
 미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기 전에 탈출할 수 있는지의 여부, 얼마나 빨리 탈출할 수 있는지를 결정
 매 분마다 한칸씩 (상하좌우) 이동
 미로의 가장자리에서 탈출 가능
 벽 통과 불가
 */

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let R = input[0]
let C = input[1]
var array = [[String]]()
for _ in 0..<R {
    array.append(readLine()!.map{ String($0) })
}

var fireQueue = [(Int, Int)]()
var jihoonQueue = [(Int, Int)]()
var fire = [[Int]](repeating: [Int](repeating: 0, count: C), count: R)
var jihoon = [[Int]](repeating: [Int](repeating: 0, count: C), count: R)
let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]

for i in 0..<R {
    for j in 0..<C {
        if array[i][j] == "J" {
            jihoonQueue.append((i, j))
            jihoon[i][j] = 1
        }else if array[i][j] == "F" {
            fireQueue.append((i, j))
            fire[i][j] = 1
        }
    }
}

//불 BFS로 미로의 각 위치에 불이 언제 도착했는지 작성해놓기
func fireBFS(){
    var front = 0
    while fireQueue.count > front {
        let (x, y) = fireQueue[front]
        front += 1
        
        for i in 0..<4 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            guard (0..<R) ~= dx, (0..<C) ~= dy else { continue }
            if array[dx][dy] != "#", fire[dx][dy] == 0 { //벽이 아니고, 방문한 곳도 아니라면
                fire[dx][dy] = fire[x][y] + 1
                fireQueue.append((dx, dy))
            }
        }
    }
}

func jihoonBFS(){
    var front = 0
    while jihoonQueue.count > front {
        let (x, y) = jihoonQueue[front]
        front += 1
        
        for i in 0..<4 {
            let dx = x + direction[i][0]
            let dy = y + direction[i][1]
            guard (0..<R) ~= dx, (0..<C) ~= dy else { //가장자리 -> 탈출
                print(jihoon[x][y])
                return
            }
            if array[dx][dy] == "#" || jihoon[dx][dy] != 0 { //벽이거나, 방문했던 곳이라면 패스
                continue
            }
            if fire[dx][dy] != 0, fire[dx][dy] <= jihoon[x][y] + 1 { //불이 먼저 도착한 곳이라면
                continue //여기 못가
            }
            jihoon[dx][dy] = jihoon[x][y] + 1
            jihoonQueue.append((dx, dy))
        }
    }
    print("IMPOSSIBLE")
}

fireBFS()
jihoonBFS()
