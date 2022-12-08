import java.util.Scanner;
import java.util.Stack;

class Main {
    public static String solution(String str) {
        Stack<Character> st = new Stack<>();
        for(char ch : str.toCharArray()) {
            if(ch=='(') st.push(ch);
            else {
                if(st.isEmpty()) return "NO";
                st.pop();
            }
        }
        if(st.isEmpty()) return "YES";
        else return "NO";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine().trim();
        System.out.println(solution(str));
    }//main

}//class
