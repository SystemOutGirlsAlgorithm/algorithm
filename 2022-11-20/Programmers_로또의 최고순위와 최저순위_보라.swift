import Foundation

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
//    let zeroCount = lottos.filter { $0 == 0}.count
//    let winCount: Int = win_nums.filter { lottos.contains($0) }.count
//    return [min(7-winCount-zeroCount,6), min(7-winCount,6)]
    
    let lotto = lottos.sorted()
    let winNum = win_nums.sorted()
    let check = lotto.filter{$0 == 0}.count
    
    var maxCnt = 0
    var minCnt = 0
    
    if check == 6 {
        return [1,6]
    }

    for i in 0 ..< lotto.count {
        for j in 0 ..< lotto.count {
            if lotto[i] == winNum[j] {
                minCnt += 1
            }
        }
    }

    maxCnt = minCnt + check

    let res = [minCnt, maxCnt]

    return res.map {
        switch $0 {
        case 6: return 1
        case 5: return 2
        case 4: return 3
        case 3: return 4
        case 2: return 5
        default: return 6

        }
    }.sorted()
}

print(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]))
