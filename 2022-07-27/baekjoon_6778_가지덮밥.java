import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int antenna = sc.nextInt();
        int eyes = sc.nextInt();

        if(antenna >= 3 && eyes <=4)
        	System.out.println("TroyMartian");
        if(antenna <= 6 && eyes >= 2)
        	System.out.println("VladSaturnian");
        if(antenna <= 2 && eyes <= 3)
        	System.out.println("GraemeMercurian");
    }
}