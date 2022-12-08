import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    public void solution(int n, int m, int[][] graph) {
        int[] roots = new int[n + 1];
        init(roots);

        for (int i = 0; i < graph.length; i++) {
            union(roots, graph[i][0], graph[i][1]);
        }
//        System.out.println(Arrays.toString(roots));

        Set<Integer> connections = new HashSet<>();
        for (int i = 1; i < roots.length; i++) {
            connections.add(findRoot(roots, i));
        }
        System.out.println(connections.size());
    }

    public void init(int[] roots) {
        for (int i = 1; i < roots.length; i++) {
            roots[i] = i;
        }
    }

    public int findRoot(int[] roots, int n) {
        if (n != roots[n]) {
            roots[n] = findRoot(roots, roots[n]);
        }
        return roots[n];
    }

    public void union(int[] roots, int a, int b) {
        int aRoot = findRoot(roots, a);
        int bRoot = findRoot(roots, b);
        if (aRoot < bRoot) {
            roots[bRoot] = aRoot;
        } else {
            roots[aRoot] = bRoot;
        }
    }

    public static void main(String[] args) throws IOException {
        Main main = new Main();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] info = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int[][] graph = new int[info[1]][2];
        for (int i = 0; i < info[1]; i++) {
            graph[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        main.solution(info[0], info[1], graph);
    }
}