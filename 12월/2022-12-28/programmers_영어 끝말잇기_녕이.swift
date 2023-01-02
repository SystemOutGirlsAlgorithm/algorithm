import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var record = [String]()
    var last = words[0].first!
    for word in words {
        if record.contains(word) || word.first! != last { //중복 글자 혹은 실패의 경우
            return [(record.count % n + 1), (record.count / n + 1)]
        }
        last = word.last!    //마지막 글자
        record.append(word)
    }
    return [0, 0]
}
