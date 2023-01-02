import Foundation

var N = Array(readLine()!)
var array = Array(repeating: 0, count: 10)
var answer = 0
for element in N { array[Int(String(element))!] += 1 }
for i in 0..<10 {
    guard i != 6, i != 9 else { continue }
    answer = Int(String(array[i]))! > answer ? Int(String(array[i]))! : answer
}
print(max(answer, Int((array[6] + array[9] + 1) / 2)))
