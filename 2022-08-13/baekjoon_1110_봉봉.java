
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input_number = br.readLine();
        String number = input_number ;

        int loop = 0;

        while(true) {
            if (Integer.parseInt(number) < 10 && number.length()==1) {
                number = "0" + number;
                //case 55에서  05가 이미 붙어서 문자열의 길이가 2인데 앞에 0이 붙어 005가 되는 사태를 방지하기 위함 
            }

            int second = Integer.parseInt(String.valueOf(number.charAt(1)));
            int third = Integer.parseInt(String.valueOf(number.charAt(0))) + second;

            //System.out.println(second+":"+third);

            if(third>=10){
                third = third %10;
            }

            number = Integer.toString(second) + Integer.toString(third);

            loop = loop+1;

            if(Integer.parseInt(input_number) == Integer.parseInt(number)){
                System.out.println(loop);
                break;
            }


        }








    }
}
