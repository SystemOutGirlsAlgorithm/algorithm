// 풀긴 풀었는데 제시된 문제에서 왜 answer를 -1로 초기화시킨 상태로 제시했는지 모르겠음
class Solution {
    public int solution(int num1, int num2) {
        int answer = -1;
        if((num1>=0&&num1<=100)&&(num2>=0&&num2<=100)){
            answer = num1 % num2;
        }
        return answer;
    }
}
