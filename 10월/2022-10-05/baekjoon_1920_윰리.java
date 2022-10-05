import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String str = br.readLine();
        String[] arr = str.split(" ");
        int[] nArr = Arrays.stream(arr).mapToInt(Integer::parseInt).toArray();

        int m = Integer.parseInt(br.readLine());
        str = br.readLine();
        arr = str.split(" ");
        int[] mArr = Arrays.stream(arr).mapToInt(Integer::parseInt).toArray();

        Arrays.sort(nArr);
        for (int i = 0; i < m; i++) {
            int result = 1;
            if (Arrays.binarySearch(nArr, mArr[i]) < 0) {
                result = 0;
            }
            System.out.println(result);
        }
    }
}