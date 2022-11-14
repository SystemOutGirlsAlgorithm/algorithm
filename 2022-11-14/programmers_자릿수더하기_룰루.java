/*import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;

        String[] arr = String.valueOf(n).split("");

        for(String a : arr){
            answer += Integer.parseInt(a);
        }

        return answer;
    }
}
*/
/*
1. string-Int 형변환 중 Integer.toString() vs String.valueOf() 차이
2. split / substring 문자열 나누기
3. 문자열 분열 말고 단순하게 푸는 방법도 존재

*/

import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;

        while(n>0){
            answer += n % 10; // 일의자리수부터 차례로 더하기
            n /= 10; //더한 자리수 제거
        }

        return answer;
    }
}