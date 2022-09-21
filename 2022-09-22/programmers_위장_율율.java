// 위장
import java.util.*;

public class Main {
	public static int solution(String[][] clothes) {
        int answer = 1;
        
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for(String[] sArr : clothes) {
        	String type = sArr[1];
        	map.put(type, map.getOrDefault(type, 0)+1); // key가 이전에 존재하지 않으면 디폴트값 0+1, 존재하면 존재하는 수+1
        }
        
        Iterator<Integer> it = map.values().iterator();
        while(it.hasNext()) {
        	answer*=(it.next().intValue()+1);
        }
        
        return answer-1;
    }

	public static void main(String[] args) {
		String[][] clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
		solution(clothes);
	}

}
