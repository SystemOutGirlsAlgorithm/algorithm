package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class n1976 {
    static int N, M;
    static int[] parent;

    static int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    static void union_root(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x != y) {
            if (x > y)
                parent[x] = y;
            else
                parent[y] = x;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        parent = new int[N+1];
        for (int i = 1; i <= N; ++i) {
            parent[i] = i;
        }


        int connect;
        for (int i = 1; i <= N; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; ++j) {
                connect = Integer.parseInt(st.nextToken());

                if (connect == 1) {
                    union_root(i, j);
                }
            }
        }


        st = new StringTokenizer(br.readLine());
        int start = findParent(Integer.parseInt(st.nextToken()));
        for (int i = 1; i < M; ++i) {
            int node = Integer.parseInt(st.nextToken());
            if (start != findParent(node)) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }
}
