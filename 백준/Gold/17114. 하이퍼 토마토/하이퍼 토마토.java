import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    static int[] da = {-1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static int[] db = {0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static int[] dc = {0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static int[] dd = {0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static int[] de = {0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static int[] df = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static int[] dg = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    static int[] dh = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0};
    static int[] di = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0};
    static int[] dj = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0};
    static int[] dk = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int m = Integer.parseInt(line[0]);
        int n = Integer.parseInt(line[1]);
        int o = Integer.parseInt(line[2]);
        int p = Integer.parseInt(line[3]);
        int q = Integer.parseInt(line[4]);
        int r = Integer.parseInt(line[5]);
        int s = Integer.parseInt(line[6]);
        int t = Integer.parseInt(line[7]);
        int u = Integer.parseInt(line[8]);
        int v = Integer.parseInt(line[9]);
        int w = Integer.parseInt(line[10]);

        int[][][][][][][][][][][] storage = new int[w][v][u][t][s][r][q][p][o][n][m];
        Deque<Node> deque = new ArrayDeque<>();

        for (int a = 0; a < w; a++)
            for (int b = 0; b < v; b++)
                for (int c = 0; c < u; c++)
                    for (int d = 0; d < t; d++)
                        for (int e = 0; e < s; e++)
                            for (int f = 0; f < r; f++)
                                for (int g = 0; g < q; g++)
                                    for (int h = 0; h < p; h++)
                                        for (int i = 0; i < o; i++)
                                            for (int j = 0; j < n; j++) {
                                                line = br.readLine().split(" ");
                                                for (int k = 0; k < m; k++) {
                                                    int num = Integer.parseInt(line[k]);
                                                    storage[a][b][c][d][e][f][g][h][i][j][k] = num;

                                                    if (num == 1)
                                                        deque.offerLast(new Node(0, new Coordinate(a, b, c, d, e, f, g, h, i, j, k)));
                                                }
                                            }

        int max = 0;

        while (!deque.isEmpty()) {
            Node node = deque.pollFirst();
            Coordinate coordinate = node.coordinate;

            if (max < node.level)
                max = node.level;

            for (int i = 0; i < 22; i++) {
                int newA = coordinate.a + da[i];
                int newB = coordinate.b + db[i];
                int newC = coordinate.c + dc[i];
                int newD = coordinate.d + dd[i];
                int newE = coordinate.e + de[i];
                int newF = coordinate.f + df[i];
                int newG = coordinate.g + dg[i];
                int newH = coordinate.h + dh[i];
                int newI = coordinate.i + di[i];
                int newJ = coordinate.j + dj[i];
                int newK = coordinate.k + dk[i];

                if (newA >= 0 && newA < w
                        && newB >= 0 && newB < v
                        && newC >= 0 && newC < u
                        && newD >= 0 && newD < t
                        && newE >= 0 && newE < s
                        && newF >= 0 && newF < r
                        && newG >= 0 && newG < q
                        && newH >= 0 && newH < p
                        && newI >= 0 && newI < o
                        && newJ >= 0 && newJ < n
                        && newK >= 0 && newK < m
                        && storage[newA][newB][newC][newD][newE][newF][newG][newH][newI][newJ][newK] == 0) {
                    deque.offerLast(new Node(node.level + 1,
                            new Coordinate(newA, newB, newC, newD, newE, newF, newG, newH, newI, newJ, newK)));
                    storage[newA][newB][newC][newD][newE][newF][newG][newH][newI][newJ][newK] = 1;
                }
            }
        }

        boolean isAllRipened = true;

        for (int a = 0; a < w; a++)
            for (int b = 0; b < v; b++)
                for (int c = 0; c < u; c++)
                    for (int d = 0; d < t; d++)
                        for (int e = 0; e < s; e++)
                            for (int f = 0; f < r; f++)
                                for (int g = 0; g < q; g++)
                                    for (int h = 0; h < p; h++)
                                        for (int i = 0; i < o; i++)
                                            for (int j = 0; j < n; j++) {
                                                for (int k = 0; k < m; k++) {
//                                                    System.out.print(storage[a][b][c][d][e][f][g][h][i][j][k] + " ");
                                                    if (storage[a][b][c][d][e][f][g][h][i][j][k] == 0)
                                                        isAllRipened = false;
                                                }
//                                                System.out.println();
                                            }

        if (isAllRipened)
            System.out.println(max);
        else
            System.out.println(-1);
    }

    static class Node {
        public int level;
        public Coordinate coordinate;

        public Node(int level, Coordinate coordinate) {
            this.level = level;
            this.coordinate = coordinate;
        }
    }

    static class Coordinate {
        public final int a;
        public final int b;
        public final int c;
        public final int d;
        public final int e;
        public final int f;
        public final int g;
        public final int h;
        public final int i;
        public final int j;
        public final int k;

        public Coordinate(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
            this.e = e;
            this.f = f;
            this.g = g;
            this.h = h;
            this.i = i;
            this.j = j;
            this.k = k;
        }
    }

}