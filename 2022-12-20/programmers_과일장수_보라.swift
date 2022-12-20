import Foundation

//func solution(_ k:Int, _ m:Int, _ score:[Int]) -> Int {
//    var ans = 0
//
//    let mod = score.count % m
//    let score = score.sorted(by: >)[0..<score.count - mod]
//
//    for i in stride(from: 0, to: score.count, by: m) {
//        ans += Array(score[i..<i+m]).min()! * m
//    }
//
//    return ans
//}
func solution(_ k:Int, _ m:Int, _ score:[Int]) -> Int {
    let scoreOrder = score.sorted(by: >)
    var profit: [[Int]] = []
    var box: [Int] = []
    var res: [Int] = []
    var cnt = 0
    
    _ = scoreOrder.map { s in
        if cnt == m {
            profit.append(box)
            box = []
            cnt = 1
        }
        else {
            cnt += 1
        }
        box.append(s)
    }
    
    if box.count == m {
        profit.append(box)
    }
    
    for i in 0 ..< profit.count {
        let min = profit[i].min()
        let appleCnt = profit[i].count
        res.append(min! * appleCnt)
    }
    
    return res.reduce(0, +)
}
//print(solution(3, 4, [1, 2, 3, 1, 2, 3, 1]))
print(solution(4, 3, [4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2]))
