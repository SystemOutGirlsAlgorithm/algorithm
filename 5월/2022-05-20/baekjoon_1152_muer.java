import java.util.Scanner;

public class baekjoon_1152_muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String content = scanner.nextLine();

        String[] words = content.split(" ");

        if(content.charAt(0) == ' ' && content.length() > 1){
            System.out.println(words.length -1);
        }else {
            System.out.println(words.length);
        }

    }
}
