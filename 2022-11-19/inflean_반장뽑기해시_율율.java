import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {
    public static char solution(int n, String str) {
        char answer = ' ';
        // 1. str을 한글자씩 나누기 2. if-else로 key값이 존재하지 않으면 put(key,new Integer(1)) 3. 존재하면 put(key, value+1)
        /*HashMap<Character, Integer> map = new HashMap<>(n);
        for(char c : str.toCharArray()){
            if(map.containsKey(c)) {
                Integer value = map.get(c);
                map.put(c, value + 1);
            }else {
                map.put(c, 1);
            }
        }*/

        HashMap<Character, Integer> map = new HashMap<>(n);
        for (char c : str.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0)+1);
        }

        // 4. 가장 큰 value값의 key를 리턴 (Map.Entry이용)
        // Map.Entry는 Iterator보다 ForEach사용 권장
        int max = 0;
        /*for(Map.Entry<Character,Integer> entry : map.entrySet()) {
            int value = entry.getValue();
            if(value > max) {
                max = value;
                answer = entry.getKey();
            }
        }*/

        for (char key : map.keySet()) {
            int value = map.get(key);
            if (value > max) {
                max = value;
                answer = key;
            }
        }
        //System.out.println(map);
        return answer;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());
        String str = sc.nextLine().trim();
        System.out.println(solution(n, str));
    }//main

}//class
