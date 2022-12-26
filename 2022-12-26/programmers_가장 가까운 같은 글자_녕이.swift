import Foundation

/*
 s의 각 위치마다 자신보다 앞에 나와있고, 자신과 가장 가까운 곳에 있는 같은 글자가 어디 있는지 알고싶다.
 dictionary updateValue 사용해서 구현
 */

func solution(_ s:String) -> [Int] {
    var answer = [Int]()
    var array = s.map{ String($0) }
    var dictionary = [String: Int]()
    for i in 0..<array.count {
        var str = array[i]
        if dictionary[str] == nil { //dictionary에 없으면
            answer.append(-1)       //처음 나왔으므로 -1
            dictionary[str] = i     //dictionary에 인덱스 추가하기
        }else {
            answer.append(i - dictionary[str]!)
            dictionary[str] = i     //update
        }
    }
    return answer
}

print(solution("banana"))
print(solution("foobar"))
