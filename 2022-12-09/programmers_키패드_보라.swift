import Foundation

func solution(_ numbers:[Int], _ hand:String) -> String {
    let keyPad = [
        ["1", "4", "7", "10"], //왼쪽 10은 *
        ["2", "5", "8", "11"],
        ["3", "6", "9", "12"] //오른쪽 12는 #
    ]
    var res = ""
    var lefthand = [0,3]
    var righthand = [2,3]
    
    for i in numbers {
        let num = i == 0 ? 11 : i
        
//        print(keyPad[lefthand[0]][lefthand[1]], keyPad[righthand[0]][righthand[1]], num)
        if let index = keyPad[0].firstIndex(of: String(num)) { //1,4,7 경우
            lefthand = [0, index]
            res += "L"
        }
        else if let index = keyPad[1].firstIndex(of: String(num)) {
            let leftSpace = abs((lefthand[0] - 1)) + abs((lefthand[1] - index)) //왼쪽 손 거리 계산
            let rightSpace = abs((righthand[0] - 1)) + abs((righthand[1] - index)) //오른 손 거리 계산
            
            if leftSpace == rightSpace { //같으면
                if hand == "left" {
                    lefthand = [1, index]
                    res += "L"
                }
                else {
                    righthand = [1, index]
                    res += "R"
                }
            }
            else if leftSpace < rightSpace {
                lefthand = [1, index]
                res += "L"
            }
            else {
                righthand = [1, index]
                res += "R"
            }
        }
        else if let index = keyPad[2].firstIndex(of: String(num)) { //3,6,9 경우
            righthand = [2, index]
            res += "R"
        }
    }
    
    return res
}

//print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))
print(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], "left"))
