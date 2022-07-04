import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class factorizationInPrimeFactors_11653 {
	public static void main(String args[]) throws IOException{
		BufferedReader bf=new BufferedReader(new InputStreamReader (System.in));
		int N=Integer.parseInt(bf.readLine());
		
		if(N==1) {}
		else {
			while(N!=1) {
				int check=2;
				while(true) {
					if(N%check==0) {
						System.out.println(check);
						N/=check;
						break;
					}
					else {
						check++;
					}
				}
			}
		}
	}
}
