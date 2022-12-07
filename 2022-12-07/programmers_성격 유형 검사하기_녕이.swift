import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var personalityDictionary : [Character: Int] = ["R":0, "T":0, "C":0, "F":0, "J":0, "M":0, "A":0, "N":0]
    var answer = ""
    for i in 0..<survey.count {
        switch choices[i] {
        case 1...3:
            personalityDictionary[survey[i].first!]! += 3 - choices[i] + 1
        case 5...7:
            personalityDictionary[survey[i].last!]! += choices[i] - 4
        default:
            continue
        }
    }
    answer += personalityDictionary["R"]! >= personalityDictionary["T"]! ? "R" : "T"
    answer += personalityDictionary["C"]! >= personalityDictionary["F"]! ? "C" : "F"
    answer += personalityDictionary["J"]! >= personalityDictionary["M"]! ? "J" : "M"
    answer += personalityDictionary["A"]! >= personalityDictionary["N"]! ? "A" : "N"
    return answer
}

print(solution(["TR", "RT", "TR"], [7, 1, 3]))
