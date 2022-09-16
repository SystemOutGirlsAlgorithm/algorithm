import java.util.HashSet;

// 영어 끝말 잇기
public class Main {
	public static int[] solution(int n, String[] words) {
		int[] answer = {0,0};
		
		HashSet<String> set = new HashSet<String>();
		for(int i=0; i<words.length; i++) {
			if(set.add(words[i])) { // 중복된 단어 없음
				int len = words[i].length();
				String end = words[i].charAt(len-1)+"";
				if(i<words.length-1) {
					if(!words[i+1].startsWith(end)) { // 탈락
						answer[0]=((i+1)%n)+1;
						answer[1]=((i+1)/n)+1;
						break;
					}
				}
			}else { // 중복된 단어 있음 (탈락)
				answer[0]=(i%n)+1;
				answer[1]=(i/n)+1;
				break;
			}
		}
		return answer;
	}
	
	public static void main(String[] args) {
		int n = 3;
		String[] words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
		solution(n, words);
	}

}
