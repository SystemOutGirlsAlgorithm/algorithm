import java.util.Scanner;

public class Baekjoon_4153_Muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true){
            int num1 = scanner.nextInt();
            int num2 = scanner.nextInt();
            int num3 = scanner.nextInt();

            if(num1 == 0 && num2 == 0 && num3 ==0){
                break;
            } else if (Math.pow(num3, 2) == Math.pow(num1, 2) + Math.pow(num2, 2)){
                System.out.println("right");
            } else if (Math.pow(num2, 2) == Math.pow(num1, 2) + Math.pow(num3, 2)){
                System.out.println("right");
            } else if (Math.pow(num1, 2) == Math.pow(num3, 2) + Math.pow(num2, 2)){
                System.out.println("right");
            } else {
                System.out.println("wrong");
            }
        }
    }
}
