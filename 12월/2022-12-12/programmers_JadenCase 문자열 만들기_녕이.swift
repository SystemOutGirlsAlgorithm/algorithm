import Foundation

func solution(_ s:String) -> String {
    let arr = s.lowercased()
    var answer = ""
    var tmp = ""
    for str in arr {
        guard str != " " else {
            if !tmp.isEmpty {
                answer += tmp
                tmp = ""
            }
            answer += " "
            continue
        }
        tmp += tmp.isEmpty ? String(str).uppercased() : String(str)
    }
    if !tmp.isEmpty { answer += tmp }
    return answer
}
