import java.util.Scanner;

public class Baekjoon_2480 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();

        int[] input = {A, B, C};
        int result = 0;
        int record = 0;

        if(A == B && B == C){
            result = A * 1000 + 10000;
        }else if(A == B || B == C || A == C){
            if(A == B){
                result = A * 100 + 1000;
            }else if(B == C){
                result = B * 100 + 1000;
            }else{
                result = C * 100 + 1000;
            }
        }else{
            for(int i = 0; i < 3; i++){
                if(input[i] > record){
                    record = input[i];
                }
            }
            result = record * 100;
        }
        System.out.println(result);
    }
}
