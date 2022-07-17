import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int num = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        ArrayList<Integer> array = new ArrayList<>();

        for (int i = 0; i < num; i++) {
            array.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(array);

        System.out.println(array.get(0) + " " + array.get(array.size() - 1));

    }
}