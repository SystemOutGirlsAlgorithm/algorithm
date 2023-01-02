import Foundation

/*
 수빈이는 N에 있고, 동생은 K에 있다.
 수빈이는 걷거나 순간이동할 수 있다. X-1, X+1, 2*X
 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하라
 */

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = input[0]
let K = input[1]
var distance = Array(repeating: 0, count: 100001)
var queue = [Int]()
var front = 0
distance[N] = 1 //수빈이 위치
queue.append(N)

while queue.count > front {
    let pos = queue[front]
    front += 1
    let direction = [pos - 1, pos + 1, pos * 2] //이동 방법
    for i in 0..<3 {
        guard (0...100000) ~= direction[i] else { //범위를 벗어난 경우는 continue
            continue
        }
        if distance[direction[i]] == 0 { //방문한 곳이 아니라면
            distance[direction[i]] = distance[pos] + 1
            queue.append(direction[i])
        }
    }
}

print(distance[K] - 1)
