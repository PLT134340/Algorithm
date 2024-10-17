import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int n;
    static boolean[] isVisited;
    static int[][] edges = new int[10][10];
    static int max = -1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        for (int i = 0; i < m; i++) {
            String[] line = br.readLine().split(" ");

            int from = Integer.parseInt(line[0]);
            int to = Integer.parseInt(line[1]);
            int cost = Integer.parseInt(line[2]);

            if (edges[from][to] < cost)
                edges[from][to] = cost;
        }

        isVisited = new boolean[n + 1];
        recurs(0, 0, 0);

        System.out.println(max);
    }

    static void recurs(int level, int sum, int vertex) {
//        System.out.printf("level=%d sum=%d vertex=%d\n", level, sum, vertex);
        if (level == n) {
            if (edges[vertex][0] > 0 && max < sum + edges[vertex][0])
                max = sum + edges[vertex][0];
            return;
        }

        isVisited[vertex] = true;

        for (int i = 1; i <= n; i++) {
            if (isVisited[i] || edges[vertex][i] == 0)
                continue;

            recurs(level + 1, sum + edges[vertex][i], i);
        }

        isVisited[vertex] = false;
    }

}
