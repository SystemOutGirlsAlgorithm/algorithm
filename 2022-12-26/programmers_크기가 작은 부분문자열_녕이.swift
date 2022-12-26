import Foundation

func solution(_ t:String, _ p:String) -> Int {
    let length = p.count
    var answer = 0
    for i in 0...t.count-length {
        var subString = t.substring(from: i, to: length + i)
        if subString <= p {
            answer += 1
        }
    }
    return answer
}

extension String {
    func substring(from: Int, to: Int) -> String {
        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to)
        return String(self[startIndex ..< endIndex])
    }
}
