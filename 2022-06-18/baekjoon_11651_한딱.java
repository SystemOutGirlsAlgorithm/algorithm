import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	public static void main(String args[]) throws IOException{
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(bf.readLine()," ");
		
		int N=Integer.parseInt(st.nextToken());
		int[][] coordinate=new int[N][2];
		
		for(int i=0;i<coordinate.length;i++) {
			st=new StringTokenizer(bf.readLine());
			for(int j=0;j<2;j++) {
				coordinate[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		Arrays.sort(coordinate, new Comparator<int[]>() {
			public int compare(int[] o1, int[] o2) {
				if(o1[1] == o2[1]) {
					return o1[0] - o2[0];
				}
				else {
					return o1[1] - o2[1];
				}
			}
		});
		
		for(int i=0;i<coordinate.length;i++) {
			for(int j=0;j<2;j++) {
				System.out.print(coordinate[i][j]+" ");
			}
			System.out.print("\n");
		}
	}
}
