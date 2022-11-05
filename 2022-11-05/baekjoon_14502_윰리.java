import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Main {

    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};
    private static List<int[][]> newWallsGraphs;
    private static List<Point> point0s;

    public void solution(int n, int m, int[][] graph) {
        newWallsGraphs = new ArrayList<>();

        point0s = make0List(graph);
        write1(graph, new boolean[point0s.size()], 0);

        for (int[][] newWallsGraph : newWallsGraphs) {
            Point point2 = findNext2(newWallsGraph);
            while (point2 != null) {
//                System.out.println("point2 = " + point2);
                inject(newWallsGraph, point2.x, point2.y);
                point2 = findNext2(newWallsGraph);
            }
        }

        int max = 0;
        for (int[][] newWallsGraph : newWallsGraphs) {
            max = Math.max(max, countSafe0(newWallsGraph));
        }

        System.out.println(max);

    }

    public List<Point> make0List(int[][] graph) {

        List<Point> point0s = new ArrayList<>();
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph[0].length; j++) {
                if (graph[i][j] == 0) {
                    point0s.add(new Point(i, j));
                }
            }
        }

        return point0s;
    }

    public Point findNext2(int[][] graph) {
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph[0].length; j++) {
                if (graph[i][j] == 2) {
                    graph[i][j] = 0;
                    return new Point(i, j);
                }
            }
        }
        return null;
    }

    public void write1(int[][] graph, boolean[] visited, int wallCount) {
        if (3 <= wallCount) {
//            System.out.println();
//            for (int[] row : graph) {
//                System.out.println(Arrays.toString(row));
//            }
            newWallsGraphs.add(graph);
            return;
        }

        int x, y;
        for (int i = 0; i < point0s.size(); i++) {
            x = point0s.get(i).x;
            y = point0s.get(i).y;

            //방문했던 형제노드이거나 부모노드인 경우
            if (visited[i] || graph[x][y] != 0) {
                continue;
            }

            //오른쪽 형제노드만 자식노드로 방문
            graph[x][y] = 1;
            wallCount++;
            visited[i] = true;
            write1(copyGraph(graph), visited.clone(), wallCount);
            graph[x][y] = 0;
            wallCount--;
        }
    }

    public void inject(int[][] graph, int x, int y) {
        if (graph[x][y] != 0) {
            return;
        }

        graph[x][y] = -1;

        for (int i = 0; i < dx.length; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= graph.length || ny >= graph[0].length) {
                continue;
            }
            inject(graph, nx, ny);
        }
    }

    public int countSafe0(int[][] graph) {
        int count = 0;
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph[0].length; j++) {
                if (graph[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }

    public int[][] copyGraph(int[][] graph) {
        int[][] newGraph = new int[graph.length][];
        for (int i = 0; i < graph.length; i++) {
            newGraph[i] = graph[i].clone();
        }
        return newGraph;
    }

    class Point {
        private int x;
        private int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Point{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }

    public static void main(String[] args) throws IOException, CloneNotSupportedException {
        Main main = new Main();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] size = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int[][] graph = new int[size[0]][];
        for (int i = 0; i < size[0]; i++) {
            graph[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        main.solution(size[0], size[1], graph);
    }
}