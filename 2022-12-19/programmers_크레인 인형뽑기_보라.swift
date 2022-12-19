import Foundation

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
    var boardRes = board
    var box:[Int] = []
    var cnt = 0
    
    moves.map { i in
        let num = i - 1
        for j in 0 ..< boardRes.count {
            if boardRes[j][num] != 0 {
                if box.last == boardRes[j][num] {
                    cnt += 2
                    box.removeLast()
                }
                else {
                    box.append(boardRes[j][num])
                }
                boardRes[j][num] = 0
                break
            }
        }
    }
    return cnt
}
print(solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]],   [1,5,3,5,1,2,1,4]))
