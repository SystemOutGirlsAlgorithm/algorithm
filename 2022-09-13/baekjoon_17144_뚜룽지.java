package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class n17144 {
    static int R, C, T;
    static int board[][];
    static int air_x[] = {0, 0};
    static int air_y[] = {0, 0};
    static int dy[] = { 0, 1, 0, -1 };
    static int dx[] = { -1, 0, 1, 0 };

    static void printed() {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                System.out.printf("%d ", board[i][j]);
            }
            System.out.println();
        }
    }

    static int counted() {
        int ans = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                ans += board[i][j];
            }
        }
        return ans;
    }

    static void spread() {
        int new_board[][] = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == -1) new_board[i][j] = -1;
                else if (board[i][j] > 0) {
                    int cnt = 0;
                    int value = board[i][j]/5;
                    for (int k = 0; k < 4; k++) {
                        int ni = i+dx[k], nj = j+dy[k];
                        if (ni >= 0 && ni < R && nj >= 0 && nj < C && board[ni][nj] != -1 ) {
                            ++cnt;
                            new_board[ni][nj] += value;
                        }
                    }

                    new_board[i][j] += board[i][j] - value*cnt;
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                board[i][j] = new_board[i][j];
            }
        }
    }

    static void air(int x, int y, int dir) {
        int nx = x, ny = y+1;
        int look = 1;
        int temp1, temp2 = 0;
        while (nx != x || ny != y) {
            temp1 = board[nx][ny];
            board[nx][ny] = temp2;
            temp2 = temp1;

            int nnx = nx + dx[look], nny = ny + dy[look];
            if (nnx < 0 || nnx >= R || nny < 0 || nny >= C) {
                look = (4 + look + dir) % 4;
            }
            nx = nx + dx[look];
            ny = ny + dy[look];
        }
    }

    static void simulations() {
        spread();
        air(air_x[0], air_y[0], -1);
        air(air_x[1], air_y[1], 1);
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        board = new int[R][C];

        int cnt = 0;
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == -1) {
                    air_x[cnt] = i;
                    air_y[cnt++] = j;
                }
            }
        }

        while (T-- > 0) simulations();
        //printed();
        System.out.println(counted()+2);
    }
}
