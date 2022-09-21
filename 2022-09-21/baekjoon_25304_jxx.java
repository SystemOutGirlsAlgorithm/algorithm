import java.util.Scanner;

public class baekjoon_25304_jxx {
    public static void main(String[] args) {
        // 영수증
        // 구매한 물건의 가격과 개수로 계산한 총 금액이 영수증에 적힌 총 금액과 일치하면 Yes를 출력한다. 일치하지 않는다면 No를 출력한다.
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt(); // 영수증에 적힌 총 금액
        int N = sc.nextInt(); // 종류의 수
        int total = 0;

        for(int i = 0; i < N; i++){
            int a = sc.nextInt(); // 각 물건의 가격
            int b = sc.nextInt(); // 각 물건의 개수
            total += a * b;
        }
        if(total == X){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
