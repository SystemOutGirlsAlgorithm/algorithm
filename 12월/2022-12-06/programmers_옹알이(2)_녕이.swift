import Foundation

func solution(_ babbling:[String]) -> Int {
    var answer = 0
    let word = ["aya", "ye", "woo", "ma"]
    for baby in babbling {
        var tmp = baby
        for w in word {
            var firstIndex = 0
            var lastIndex = 0
            var lastSameWordsIndex = -1
            while tmp.contains(w) {
                let lower = tmp.range(of: w)!.lowerBound
                let upper = tmp.range(of: w)!.upperBound
                firstIndex = tmp.distance(from: tmp.startIndex, to: lower)
                lastIndex = tmp.distance(from: tmp.startIndex, to: upper)
                if lastSameWordsIndex == firstIndex {
                    break
                }
                lastSameWordsIndex = lastIndex
                let range = tmp.index(tmp.startIndex, offsetBy: firstIndex)...tmp.index(tmp.startIndex, offsetBy: lastIndex - 1)
                tmp.removeSubrange(range)
                for _ in 0..<(lastIndex - firstIndex) {
                    tmp.insert(contentsOf: "-", at: lower)
                }
                print(tmp)
            }
        }
        if tmp.filter({$0 == "-"}).count == tmp.count {
            answer += 1
        }
    }
    return answer
}

print(solution(["ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"]))
