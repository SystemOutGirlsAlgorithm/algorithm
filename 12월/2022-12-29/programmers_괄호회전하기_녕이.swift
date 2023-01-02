import Foundation

/*
 s를 왼쪽으로 x만큼(0...s.count)만큼 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수는?
 */

func solution(_ s:String) -> Int {
    var answer = 0
    var tmp = s
    for _ in 0..<s.count {
        func checkParentheses(_ str: String) -> Bool {
            var stack = [String]()
            for char in str {
                if stack.isEmpty {
                    if String(char) == "]" || String(char) == "}" || String(char) == ")" { return false }
                    stack.append(String(char))
                    continue
                }
                if String(char) == "(" || String(char) == "{" || String(char) == "[" {
                    stack.append(String(char))
                } else {
                    if String(char) == ")", stack.last! == "(" {
                        stack.removeLast()
                    } else if String(char) == "]", stack.last! == "[" {
                        stack.removeLast()
                    } else if String(char) == "}", stack.last! == "{" {
                        stack.removeLast()
                    } else {
                        return false
                    }
                }
            }
            return stack.isEmpty ? true : false
        }
        if checkParentheses(tmp) {
            answer += 1
        }
        tmp.append(tmp.removeFirst())
    }
    return answer
}

print(solution("[](){}"))
print(solution("}]()[{"))
print(solution("[)(]"))
print(solution("}}}"))
