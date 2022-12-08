import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    public void solution(int n, int[] houses) {

        Arrays.sort(houses);

        System.out.println(houses[(n - 1) / 2]);
    }

    public static void main(String[] args) throws IOException, CloneNotSupportedException {
        Main main = new Main();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] houses = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        main.solution(n, houses);
    }
}