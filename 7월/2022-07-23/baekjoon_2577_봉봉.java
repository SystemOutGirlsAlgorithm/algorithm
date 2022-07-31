
import java.io.*;

public class baekjoon_2577 {
    //Problem 2577
    //세 개의 자연수 A, B, C가 주어질 때 A × B × C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.
    //배열을 이용하여 0-9의 숫자가 몇개씩 들어있는지 저장하려함
    //배열의 인덱스가 곧,무슨숫자를 가지고 있는지 보여주기 때문


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int number = 1;
        int[] arr = new int[10];

        for(int i=0;i<3;i++){
            number *= Integer.parseInt(br.readLine());
        }

        for(char ch: Integer.toString(number).toCharArray()){

            int index = Character.getNumericValue(ch);
            arr[index] += 1;

        }

        for(Integer s :arr){
            System.out.println(s);
        }


    }

}
