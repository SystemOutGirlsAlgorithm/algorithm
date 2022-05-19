import java.util.Scanner;

public class baekjoon_2920_muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] num = new int[8];

        for(int i = 0;  i < 8; i++){
            num[i] = scanner.nextInt();
        }

        String result = "";
        for (int i = 0; i < num.length-1; i++) {
            if (num[i] == num[i + 1] -1) {
                result = "ascending";
            }else if(num[i] == num[i+1]+1){
                result = "descending";
            }else {
                result = "mixed";
                break;
            }
         }

        System.out.println(result);

        /*
            String result = "";
            for (int i = 0; i < num.length-1; i++) {
                if (num[i]+1 == num[i + 1]) {
                    result = "ascending";
                }else if(num[i+1] == num[i]-1){
                    result = "descending";
                }else {
                    result = "mixed";
                    break;
                }
             }

            System.out.println(result);
        */
     }
}
