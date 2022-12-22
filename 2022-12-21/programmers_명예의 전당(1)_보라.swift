import Foundation

//func solution(_ k:Int, _ score:[Int]) -> [Int] {
//    var top: [Int] = []
//    var res: [Int] = []
//
//    for i in 0 ..< score.count {
//        if top.count == k {
//            if top.min()! < score[i] {
//                let index = Int(top.firstIndex(of: top.min()!)!)
//                top[index] = score[i]
//            }
//        }
//        else {
//            top.append(score[i])
//        }
//
//        res.append(top.min()!)
//    }
//
//    return res
//}

func solution(_ k:Int, _ score:[Int]) -> [Int] {
    return (0 ..< score.count).map {
        let end = $0 < k-1 ? $0 : k-1
        return Array(score[0...$0].sorted(by: >)[0...end]).last!
    }
}

print(solution(3, [10, 100, 20, 150, 1, 100, 200]))
