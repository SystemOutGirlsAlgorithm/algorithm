import Foundation

func solution(_ s:String) -> [Int] {
    var contain: [Character] = []
    return s.map { s in
        if !contain.contains(s) {
            contain.append(s)
            return -1
        }
        else {
            let beforeindex = contain.lastIndex(of: s)
            contain.append(s)
            let index = contain.lastIndex(of: s)
            
            let distance = index! - beforeindex!
            return distance
        }
    }
}

print(solution("foobar"))
