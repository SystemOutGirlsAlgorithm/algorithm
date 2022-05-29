import java.util.Scanner;

public class baekjoon_2908_muer {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int[] n = new int[2];


        for (int i = 0; i < n.length; i++){
            n[i] = scanner.nextInt();
        }

        int res;

        int[] num = new int[2];

        for(int j = 0; j < num.length; j++){
            for (int i = 2; i >= 0; i--){
                // 100, 10 , 1
                res = n[j] / (int) Math.pow(10, i); // 7, 3, 4
                n[j] -= res * (int)Math.pow(10, i);

                if(i == 2){
                    num[j] += res;
                }else if(i == 1){
                    num[j] += res * 10;
                }else {
                    num[j] += res * 100;
                }
            }
        }

        res = Math.max(num[0], num[1]);

        System.out.println(res);
    }
}
