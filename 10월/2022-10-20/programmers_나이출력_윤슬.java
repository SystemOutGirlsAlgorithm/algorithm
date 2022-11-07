// 2022년도 기준 나이 출력
class Solution {
    public int solution(int age) {
        int answer = 0;
        if(0<age && age <=120){  
            answer = 2022 - age +1;
        }
        return answer;
    }
}

// 현재 연도 기준 나이 출력
import java.time.LocalDate;
class Solution {
    public int solution(int age) {
        int answer = 0;
        LocalDate date = LocalDate.now();
        int year = date.getYear();
        if(0<age && age <=120){  
            answer = year - age +1;
        }
        return answer;
    }
}
