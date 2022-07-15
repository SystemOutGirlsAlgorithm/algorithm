import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> array = new ArrayList<>();

        for (int i = 0; i < 9; i++) {
            array.add(Integer.parseInt(br.readLine()));
        }
        ArrayList<Integer> clone = new ArrayList<>(array);

        Collections.sort(array);

        int max = array.get(array.size() - 1);

        System.out.println(max);
        System.out.println(clone.indexOf(max) + 1);

    }
}
