import Foundation

/*
 NxN 크기에 사탕 채워져있다. (사탕 색은 모두 같지 않을 수 있다 -> 같을 수도 있다)
 사탕의 색이 다른 인접한 두 칸을 고르고 사탕을 서로 교환
 모두 같은 색으로 이어져있는 가장 긴 연속 부분(행/열)을 고르고 그 사탕들을 모두 먹는다
 상근이가 먹을 수 있는 사탕의 최대 개수는?
 Brute Force로 풀어보기 --> (3 <= N <= 50) 가능
 */

//쓸데없는 연산/시간을 줄이기 위해 swap되어 변한 row, col만 체크
func calculateMaximumNumberOfCandy(check1: Int, check2: Int, check3: Int, isRow: Bool, tmpArray: inout [[String]]) -> Int { //연속으로 이어진 같은 색의 사탕 개수 최댓값 구하기
    var max = 0
    if isRow {
        var count = 1
        var last = tmpArray[check1][0]
        for i in 1..<N {
            if last == tmpArray[check1][i] {
                count += 1
                max = max < count ? count : max //update maximum value
            }else {
                last = tmpArray[check1][i]
                count = 1
            }
        }
        count = 1
        last = tmpArray[0][check2]
        for i in 1..<N {
            if last == tmpArray[i][check2] {
                count += 1
                max = max < count ? count : max //update maximum value
            }else {
                last = tmpArray[i][check2]
                count = 1
            }
        }
        count = 1
        last = tmpArray[0][check3]
        for i in 1..<N {
            if last == tmpArray[i][check3] {
                count += 1
                max = max < count ? count : max //update maximum value
            }else {
                last = tmpArray[i][check3]
                count = 1
            }
        }
    }else {
        var count = 1
        var last = tmpArray[check1][0]
        for i in 1..<N {
            if last == tmpArray[check1][i] {
                count += 1
                max = max < count ? count : max //update maximum value
            }else {
                last = tmpArray[check1][i]
                count = 1
            }
        }
        count = 1
        last = tmpArray[0][check2]
        for i in 1..<N {
            if last == tmpArray[i][check2] {
                count += 1
                max = max < count ? count : max //update maximum value
            }else {
                last = tmpArray[i][check2]
                count = 1
            }
        }
        count = 1
        last = tmpArray[check3][0]
        for i in 1..<N {
            if last == tmpArray[check3][i] {
                count += 1
                max = max < count ? count : max //update maximum value
            }else {
                last = tmpArray[check3][i]
                count = 1
            }
        }
    }
    return max
}

//input
let N = Int(readLine()!)!
var array = [[String]]()
for _ in 0..<N {
    array.append(readLine()!.map{ String($0) })
}
var answer = 0
let direction = [[1, 0], [-1, 0], [0, 1], [0, -1]] //0,1: 상하, 2,3: 좌우
var earlyExit = false

//이미 한줄이 같은 색의 사탕으로 되어있는 경우 -> 바로 출력
// Row
for i in 0..<N {
    if N == array[i].filter({ $0 == array[i][0] }).count {
        print(N)
        earlyExit = true
    }
}

// Col
for i in 0..<N {
    var count = 1
    let last = array[0][i]
    for j in 1..<N {
        if last != array[j][i] {
            break
        }
        count += 1
        if count == N {
            print(N)
            earlyExit = true
        }
    }
}

if !earlyExit {
    //전체 원소 순회
    for i in 0..<N {
        for j in 0..<N {
            for k in 0..<4 { //swap할 원소
                let dx = i + direction[k][0]
                let dy = j + direction[k][1]
                guard (0..<N) ~= dx, (0..<N) ~= dy else { continue } //범위 내에 있는 사탕만
                guard array[dx][dy] != array[i][j] else { continue } //색이 서로 다른 사탕만
                var tmp = array //copy array
                let tmpCandy = tmp[dx][dy]
                tmp[dx][dy] = tmp[i][j]         //swap
                tmp[i][j] = tmpCandy            //swap
                let result = (0...1) ~= k ? calculateMaximumNumberOfCandy(check1: i, check2: j, check3: dy, isRow: true, tmpArray: &tmp)
                                          : calculateMaximumNumberOfCandy(check1: i, check2: j, check3: dx, isRow: false, tmpArray: &tmp)
                answer = answer < result ? result : answer
            }
        }
    }
    print(answer)
}
