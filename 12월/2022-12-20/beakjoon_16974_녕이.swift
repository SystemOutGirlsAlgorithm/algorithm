import Foundation

/*
 레벨-0 버거: 패티만
 레벨-L 버거: 햄버거번, 레벨L-1버거, 패티, 레벨L-1버거, 햄버거번
 예) 레벨-1버거: BPPPB (햄버거번, 레벨L0버거, 패티, 레벨L0버거, 햄버거번)
    레벨-2버거: BBPPPBPBPPPBB (햄버거번, 레벨1버거, 패티, 레벨1버거, 햄버거번)
 레벨N버거를 시켰다. 아래서부터 X장을 먹었을 때, 먹은 패티는 몇 장?
 */

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let n = input[0]
let x = Int64(input[1])
var answer : Int64 = 0
var ingredient = [Int64](repeating: 0, count: 51)
var patty = [Int64](repeating: 0, count: 51)
ingredient[0] = 1
patty[0] = 1
for i in 1...n {
    ingredient[i] = 3 + ingredient[i-1] * 2
    patty[i] = 1 + patty[i-1] * 2
}

func countPatty(n: Int, x: Int64) -> Int64 {
    guard n != 0 else { //Level0버거
        return x == 1 ? 1 : 0
    }
    guard x != 1 else { //맨 처음은 빵
        return 0
    }
    guard x != ingredient[n] else {
        return patty[n]
    }
    
    if x == 2 + ingredient[n - 1] {
        return patty[n - 1] + 1
    }else if x <= 1 + ingredient[n - 1] {
        return countPatty(n: n - 1, x: x - 1)
    }else if x > 2 + ingredient[n - 1] {
        //이미 먹은 (빵 + level-1버거 + 패티) + 다음 부분
        return patty[n - 1] + 1 + countPatty(n: n - 1, x: x - (2 + ingredient[n - 1]))
    }
    return 0
}
print(countPatty(n: n, x: x))
