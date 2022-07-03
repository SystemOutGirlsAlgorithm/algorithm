import java.util.*;

public class baekjoon_10814_1_Muer {
    public static void main(String[] args) {
        // 시간초과 문제 발생함
        Scanner scanner = new Scanner(System.in);

        int num = scanner.nextInt();

        ArrayList<Member> members = new ArrayList<>();

        for(int i = 0; i < num; i++){
            members.add(new Member(scanner.nextInt(), scanner.next()));
        }

        Member temp;
        for(int i = 0; i < num; i++){
            for(int j = i+1; j < num; j++){
                if(members.get(i).memberScore > members.get(j).memberScore){
                    temp = members.get(i);
                    members.set(i, members.get(j));
                    members.set(j, temp);
                }
            }
        }

        for(int i = 0; i < num; i++){
            System.out.println(members.get(i).memberName+" "+members.get(i).memberScore);
        }
    }
}

class Member {
    String memberName;
    int memberScore;

    public Member() {
    }

    public Member(int memberScore, String memberName) {
        this.memberName = memberName;
        this.memberScore = memberScore;
    }
}
