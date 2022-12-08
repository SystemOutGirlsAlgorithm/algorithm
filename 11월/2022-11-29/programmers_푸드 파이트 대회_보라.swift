import Foundation

func solution(_ food:[Int]) -> String {
    var res = ""
    
    for i in 1 ..< food.count {
        res += String(repeating: "\(i)", count: food[i] / 2)
    }
    
    return res + "0" + res.reversed()
}

print(solution([1,3,4,6]))
