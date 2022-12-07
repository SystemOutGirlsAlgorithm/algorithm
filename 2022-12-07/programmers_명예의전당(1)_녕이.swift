import Foundation

func solution(_ k:Int, _ score:[Int]) -> [Int] {
    var answer = [Int]()
    var honor = [Int]()
    for sc in score {
        if honor.count < k {
            honor.append(sc)
        }
        if sc > honor.min()! {
            honor.removeLast()
            honor.append(sc)
            honor.sort(by: >)
        }
        answer.append(honor.last!)
    }
    return answer
}

print(solution(3, [10,100,20,150,1,100,200]))
