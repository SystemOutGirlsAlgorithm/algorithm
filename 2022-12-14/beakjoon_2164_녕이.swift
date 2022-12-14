import Foundation

/*
 N장의 카드, 1번 카드가 제일 위에, N번 카드가 제일 아래
 1. 제일 위에 있는 카드 버리기
 2. 제일 위 카드를 제일 아래로 옮기기
 3. 한 장 남을 때까지 반복
 */

let N = Int(readLine()!)!
var card = Array(1...N)
var top = 0
if N == 1 {
    print(1)
}else {
    while true {
        card[top] = 0                   //1. 제일 위 카드 버리기
        card.append(card[top + 1])      //2-1. 제일 위 카드 제일 아래로 옮기기
        card[top + 1] = 0               //2-2. 제일 위 카드 없애기
        if card[card.count - 2] == 0 {  //앞에서부터 0이 채워짐
            break
        }
        top += 2
    }
    print(card[card.count - 1])
}
