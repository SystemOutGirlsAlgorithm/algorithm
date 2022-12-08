import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
//    coreDump
//    var lostNum = lost.sorted()
//    var reserveNum = reserve.sorted()
//    var res: [Bool] = []
//
//    for _ in 1 ... n {
//        res.append(true)
//    }
//
//    for i in 0 ..< lostNum.count {
//        if let index = reserveNum.firstIndex(of: lostNum[i]) {
//            lostNum[i] = -1
//            reserveNum.remove(at: index)
//        }
//    }
//
//    for i in 0 ..< reserveNum.count{
//        if lostNum.contains(reserveNum[i] - 1){
//            let idx = lostNum.firstIndex(of: reserveNum[i] - 1)
//            lostNum.remove(at: idx!)
//            continue
//        }
//        if lostNum.contains(reserveNum[i] + 1){
//            let idx = lostNum.firstIndex(of: reserveNum[i] + 1)
//            lostNum.remove(at: idx!)
//        }
//
//    }
//
//    for i in 0 ..< lostNum.count {
//        res[lostNum[i]] = false
//    }
//
//    return res.filter{$0 == true}.count
    
    var result = n - lost.count
    var lostNum = lost.sorted()
    var reserveNum = reserve.sorted()
    for i in 0..<lostNum.count{
        if let idx = reserveNum.firstIndex(of: lostNum[i]){
            lostNum[i] = -1
            reserveNum.remove(at: idx)
            result += 1
        }
    }

    for i in 0..<reserveNum.count{
        if lostNum.contains(reserveNum[i] - 1){
            let idx = lostNum.firstIndex(of: reserveNum[i] - 1)
            lostNum.remove(at: idx!)
            result += 1
            continue
        }
        if lostNum.contains(reserveNum[i] + 1){
            let idx = lostNum.firstIndex(of: reserveNum[i] + 1)
            lostNum.remove(at: idx!)
            result += 1
        }

    }

    return result
}

//print(solution(5, [2,4], [1,3,5]))
//print(solution(5, [2,4], [3]))
print(solution(5, [2,3,4], [1,2,3]))
