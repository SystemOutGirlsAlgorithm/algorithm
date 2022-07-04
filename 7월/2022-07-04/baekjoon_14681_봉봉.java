import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        // StringTokenizer st = new StringTokenizer(bf.readLine());
        int x = Integer.parseInt(bf.readLine());
        int y = Integer.parseInt(bf.readLine());

        int result = 0;

        if ((x > 0 && x <= 1000) && (y > 0 && x <= 1000)) {
            result = 1;
        } else if ((x < 0 && x >= -1000) && (y > 0 && y <= 1000)) {
            result = 2;
        } else if ((x < 0 && x >= -1000) && (y < 0 && y >= -1000)) {
            result = 3;
        } else if ((x > 0 && x <= 1000) && (y < 0 && y >= -1000)) {
            result = 4;
        }

        System.out.println(result);
    }
}
