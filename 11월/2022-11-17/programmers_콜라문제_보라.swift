import Foundation

func solution(_ a:Int, _ b:Int, _ n:Int) -> Int {
    var myCoke = n // 보유 콜라
    var getCoke = 0 //교환을 통해 받은 콜라
    
    while myCoke >= a {
        getCoke += myCoke / a * b
        myCoke = (myCoke / a * b) + (myCoke % a)
    }
    
    return getCoke
}
