import java.util.Arrays;
import java.util.Scanner;

public class Baekjoon10818LM {
ㄴ
  public static void main(String[] args) throws  Exception{
    /**  input , 숫자 하나하나 받는 방법
     * */
   Scanner sc = new Scanner(System.in);
   int input = sc.nextInt();
   int[] numbers = new int[input];

   for(int i = 0; i < input; i ++){
     numbers[i] = sc.nextInt();
   }
   Arrays.sort(numbers);
   System.out.print("최소 : " + numbers[0] + ", 최대 : " + numbers[numbers.length - 1]);
  }

}ㄴ