import Foundation

/*
 원소가 n개고, 중복되는 원소가 없는 튜플이 주어질 때, {}로 표현 가능
 (a1, a2, a3, ..., an)
 -> {{a1}, {a1, a2}, {a1, a2, a3}, ..., {a1, a2, a3, ..., an}}
 */

func solution(_ s:String) -> [Int] {
    var dictionary = [Int:Int]()
    var s = s
    s.removeFirst(2)
    s.removeLast(2)
    var tuple = s.components(separatedBy: "},{").map { $0.components(separatedBy: ",").map { Int(String($0))! } }.flatMap{$0}
    for element in tuple {
        dictionary[element] = (dictionary[element] ?? 0) + 1
    }
    let sortedDictionary = dictionary.sorted { elem1, elem2 in
        return elem1.value > elem2.value
    }
    return sortedDictionary.map { $0.key }
}
