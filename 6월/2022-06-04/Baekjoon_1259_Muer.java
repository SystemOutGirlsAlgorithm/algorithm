import java.util.Scanner;

public class Baekjoon_1259_Muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String num;
        String result = "";

        while (true){

            //System.out.print("숫자를 뽑아라! >>");
            num = scanner.next();
            //System.out.println(num.length());

            for(int i = 0; i < num.length()/2+num.length()%2; i++){
                int N = (num.length()-i-1);
                //System.out.println(N);
                //System.out.println(num.charAt(N));

                if(num.charAt(i) != num.charAt(N)){
                    result = "no";
                    break;
                }else{
                    result = "yes";
                }
            }

            if(Integer.parseInt(num) == 0){
                break;
            }

            System.out.println(result);

        }
    }
}
