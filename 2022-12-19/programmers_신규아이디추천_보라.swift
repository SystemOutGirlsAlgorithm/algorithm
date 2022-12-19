import Foundation

func solution(_ new_id:String) -> String {
    let possible = "0123456789abcdefghijklmnopqrstuvwxyz-_."
    var newId = new_id
    
    //1단계
    newId = new_id.lowercased()
    
    //2단계
    newId = newId.map {
        if possible.contains($0) {
            return String($0)
        }
        else {
            return ""
        }
    }.joined()
    
    //3단계
    while newId.contains("..") {
        newId = newId.replacingOccurrences(of: "..", with: ".")
    }
    
    //4단계
    newId = newId.trimmingCharacters(in: ["."])

    //5단계
    if newId.isEmpty {
        newId = "a"
    }
    
    //6단계
    while newId.count > 15 {
        newId.removeLast()
    }
    
    if newId[newId.index(before: newId.endIndex)] == "." {
        newId.removeLast()
    }
    
    //7단계
    while newId.count < 3 {
        let last = newId[newId.index(before: newId.endIndex)]
        newId.append(last)
    }
    
    return newId
}
