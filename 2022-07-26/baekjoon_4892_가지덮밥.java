import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = 1;
        
        while(true) {
        	 int n = sc.nextInt();
        	 
        	 if(n ==0) break;
        	 
        	 if(n % 2 == 0) {
 				n = (((n * 3) / 2) * 3) / 9;
 				System.out.println(count + ". even " + n);
 			}else {
 				n = ((((n * 3) + 1) / 2) * 3) / 9;
 				System.out.println(count + ". odd " + n);
 			}
 			count++;
        }
    }
}