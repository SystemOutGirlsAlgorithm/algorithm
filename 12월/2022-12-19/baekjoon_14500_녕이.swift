import Foundation

/*
 NxM 종이 위에 테트로미노 하나를 놓으려한다.
 테트로미노 "하나"를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여있는 수들의 합을 최대로 하는 프로그램
 회전/대칭 가능
 */

let block : [[(Int, Int)]] =
            [
                //cyan
                [(0, 0), (0, 1), (0, 2), (0, 3)],
                [(0, 0), (1, 0), (2, 0), (3, 0)],
                //yellow
                [(0, 0), (0, 1), (1, 0), (1, 1)],
                //orange
                [(0, 0), (1, 0), (2, 0), (2, 1)],
                [(0, 1), (1, 1), (2, 1), (2, 0)],
                [(0, 0), (0, 1), (1, 0), (2, 0)],
                [(0, 0), (0, 1), (1, 1), (2, 1)],
                [(0, 0), (0, 1), (0, 2), (1, 2)],
                [(0, 0), (0, 1), (0, 2), (1, 0)],
                [(0, 0), (1, 0), (1, 1), (1, 2)],
                [(1, 0), (1, 1), (1, 2), (0, 2)],
                //green
                [(0, 0), (1, 0), (1, 1), (2, 1)],
                [(0, 1), (1, 0), (1, 1), (2, 0)],
                [(0, 1), (0, 2), (1, 0), (1, 1)],
                [(0, 0), (0, 1), (1, 1), (1, 2)],
                //magenta
                [(0, 0), (0, 1), (0, 2), (1, 1)],
                [(0, 1), (1, 1), (1, 0), (2, 1)],
                [(0, 0), (1, 0), (1, 1), (2, 0)],
                [(0, 1), (1, 1), (1, 0), (1, 2)]
            ]

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = input[0]
let M = input[1]
var array = [[Int]](Array(repeating: [Int](repeating: 0, count: 505), count: 505))
for i in 0..<N {
    array[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    array[i].append(contentsOf: Array(repeating: 0, count: 4)) //뒤를 0으로 채워서 out of index range를 피함
}
var answer = 0 //max value
for i in 0..<N {
    for j in 0..<M {
        for k in 0..<19 {
            var sum = 0
            for l in 0..<4 {
                sum += array[i+block[k][l].0][j+block[k][l].1]
            }
            answer = max(answer, sum)
        }
    }
}
print(answer)
