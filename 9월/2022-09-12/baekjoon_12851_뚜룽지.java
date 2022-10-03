package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair {
    int idx;
    int cost;

    Pair(int idx, int cost) {
        this.idx = idx;
        this.cost = cost;
    }
}

public class n12851 {
    static int N;
    static int K;
    static int MAX = 100001;
    static boolean[] visiting = new boolean[MAX];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        Queue<Pair> que = new LinkedList<>();
        que.offer(new Pair(N, 0));
        visiting[N] = true;

        int cnt = 0;
        int min = 987654321;

        while (!que.isEmpty()) {
            Pair curPair = que.poll();

            visiting[curPair.idx] = true;

            if (curPair.idx == K && min == curPair.cost) {
                cnt++;
            }
            else if (curPair.idx == K && min > curPair.cost ) {
                min = curPair.cost;
                cnt = 1;
            }

            if (curPair.idx+1 < MAX && !visiting[curPair.idx+1]) que.offer(new Pair(curPair.idx+1, curPair.cost+1));
            if (curPair.idx-1 >= 0 && !visiting[curPair.idx-1]) que.offer(new Pair(curPair.idx-1, curPair.cost+1));
            if (curPair.idx*2 < MAX && !visiting[curPair.idx*2]) que.offer(new Pair(curPair.idx*2, curPair.cost+1));
        }

        System.out.println(min);
        System.out.println(cnt);
    }
}
