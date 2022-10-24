package algorithm;

public class programmers_옹알이 {

	public int solution(String[] babbling) {
        int answer = 0;
        String[] canBabbling = {"aya", "ye", "woo", "ma"};
        String str = "";

        for(int i = 0; i < babbling.length; i++) {

            str = babbling[i];

            for(int j = 0; j < canBabbling.length; j++){

                if(str.matches(".*" + canBabbling[j] + ".*")) {

                    if(str.length() == canBabbling[j].length()) {
                        answer++;
                        break;
                    }


                    if(str.length() > canBabbling[j].length()) {
                         str = str.replaceAll(canBabbling[j], "");
                    }

                }
                System.out.println("STR: " + str);
            }
        }

        return answer;
    }

}
