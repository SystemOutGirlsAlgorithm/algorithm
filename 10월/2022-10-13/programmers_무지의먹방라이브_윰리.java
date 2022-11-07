import java.util.*;

class Solution {

    public int solution(int[] food_times, long k) {
        LinkedList<Food> foods = new LinkedList<>();
        for (int i = 0; i < food_times.length; i++) {
            foods.add(new Food(i, food_times[i]));
        }
        Collections.sort(foods, (o1, o2) -> o1.time - o2.time);

        long totalLoop = 0L;
        Food minFood;
        while (k >= foods.size()) { //loop 1번 이상 돌아도 k가 남으면 true
            //loop가 0이라 k가 남은 경우
            if (foods.isEmpty()) {
                break;
            }

            minFood = foods.get(0); //남은 음식중 남은 양이 제일 적은 음식
            long minTime = minFood.time;
            minTime -= totalLoop; //loop돌고 남은 양, foods 길이의 최대 loop 수

            long maxLoop = k / foods.size(); //k의 최대 loop 수
            long minLoop = Math.min(maxLoop, minTime); //가능한 loop 수
            //loop 돌리기
            totalLoop += minLoop;
            k -= minLoop * foods.size();

            //loop돌고나서 다 먹은 음식들 제거
            while (minFood.time <= totalLoop) {
                foods.removeFirst();
                if (foods.isEmpty()) {
                    break;
                }
                minFood = foods.get(0);
            }
        }

        if (foods.isEmpty()) {
            return -1;
        }

        //남은 음식 음식 순서대로 정렬
        Collections.sort(foods, (o1, o2) -> o1.num - o2.num);
        int answer = foods.get((int) k).num + 1; //k번째 음식 먹고 다음에 먹을 음식 번호
//        System.out.println("answer = " + answer);
        return answer;
    }

    class Food {
        int num;
        int time;

        public Food(int num, int time) {
            this.num = num;
            this.time = time;
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution(new int[]{3, 1, 2}, 5);
    }
}
