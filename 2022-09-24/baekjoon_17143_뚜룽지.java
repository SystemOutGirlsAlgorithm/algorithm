package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class n17143 {
    static int R, C, M;

    static int dx[] = {-1, 1, 0, 0};
    static int dy[] = {0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Shark board[][] = new Shark[R][C];

        int r, c;
        for (int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            board[r-1][c-1] = new Shark(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }


        int ans = 0;

        for (int i = 0; i < C; ++i) {
            //printest(board);
            // 잡기. 체크 먼저
            for (int j = 0; j < R; ++j) {
                if (board[j][i] != null) {
                    // 잡았다
                    //System.out.printf("catch! %d\n", board[j][i].size);
                    ans += board[j][i].size;
                    board[j][i] = null;
                    break;
                }
            }

            // 상어 이동
            Shark new_board[][] = new Shark[R][C];
            for (int x = 0; x < R; ++x) {
                for (int y = 0; y < C; ++y) {
                    if (board[x][y] != null) {
                        Shark s = board[x][y];
                        int x_ = x, y_ = y;
                        int speeds = s.speed;

                        if (s.look >= 2) speeds = speeds % ((C-1)*2);
                        else speeds = speeds % ((R-1)*2);

                        for (int t = 0; t < speeds; ++t) {
                            int nx = x_ + dx[s.look];
                            int ny = y_ + dy[s.look];
                            if (nx < 0 || nx >= R || ny < 0 || ny >= C) s.look = (s.look/2)*2 + (s.look+1)%2;
                            x_ = x_ + dx[s.look];
                            y_ = y_ + dy[s.look];
                        }
                        // 중복 상어 클리어
                        if (new_board[x_][y_] != null) {
                            Shark ns = new_board[x_][y_];
                            if (ns.size < s.size) {
                                new_board[x_][y_] = s;
                            }
                        }
                        else new_board[x_][y_] = s;
                    }
                }
            }

            for (int x = 0; x < R; ++x) {
                for (int y = 0; y < C; ++y) {
                    board[x][y] = new_board[x][y];
                }
            }
        }

        System.out.println(ans);
    }

    private static void printest(Shark[][] b) {
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (b[i][j] != null) {
                    System.out.printf("%d ", b[i][j].size);
                }
                else {
                    System.out.printf("0 ");
                }
            }
            System.out.println();
        }
        System.out.println("---------------------");
    }


    static class Shark {
        int speed, look, size;

        Shark (int s, int d, int z) {
            this.speed = s;
            this.look = d-1;
            this.size = z;
        }
    }
}
