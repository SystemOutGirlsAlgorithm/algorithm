import Foundation

func solution(_ dartResult:String) -> Int {
    let bouns: [Character: Double] = ["S": 1, "D": 2, "T": 3]
        
    var score:Double = 0.0
    var res: [Double] = []
    
    for chr in dartResult {
        var str = String(chr)
        
        if chr.isNumber {
            score = score * 10 + Double(str)!
        }
        else if chr.isLetter {
            res.append(pow(score, bouns[chr]!))
            score = 0
        }
        else {
            if chr == "*" {
                for index in [res.endIndex - 1, res.endIndex - 2] where index >= 0 {
                    res[index] *= 2
                }
            }
            if chr == "#" {
                let target = res.removeLast()
                res.append(target * -1)
            }
        }
        print(res)
//        else {
//            switch str {
//            case "S":
//                res.append(score)
//                score = 0
//            case "D":
//                res.append(score*score)
//                score = 0
//            case "T":
//                res.append(score*score*score)
//                score = 0
//            case "*":
//                for i in res.count - 1 ... res.count {
//                    res[i-1] *= 2
//                }
//            case "#":
//                res[res.count - 1] = res.last ?? 0 * (-1)
//            default:
//                print("")
//            }
//        }
        
    }
    return Int(res.reduce(0, +))
}
