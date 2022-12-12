import Foundation

func solution(_ s:String) -> [Int] {
    var tmp = s
    var zeroCount = 0
    var convertCount = 0
    repeat {
        zeroCount += tmp.filter{ $0 == "0" }.count
        convertCount += 1
        tmp = String(tmp.filter{ $0 == "1" }.count, radix: 2)
    } while tmp != "1"
    return [convertCount, zeroCount]
}
