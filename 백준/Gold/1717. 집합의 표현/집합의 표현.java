import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int n;
    static int[] roots;
    static int[] levels;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        roots = new int[n + 1];
        levels = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            roots[i] = i;
            levels[i] = 0;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < m; i++) {
            line = br.readLine().split(" ");
            boolean isUnion = line[0].equals("0");

            int a = Integer.parseInt(line[1]);
            int b = Integer.parseInt(line[2]);
            int aRoot = find(a);
            int bRoot = find(b);

            if (isUnion) {
                union(aRoot, bRoot);
                continue;
            }

            if (aRoot == bRoot) {
                sb.append("YES\n");
            } else {
                sb.append("NO\n");
            }
        }

//        for (int i = 0; i < n; i++) {
//            System.out.print(roots[i] + " ");
//        }
//        System.out.println();

        System.out.print(sb);
    }

    static void union(int v1, int v2) {
        if (levels[v1] < levels[v2]) {
            roots[v1] = v2;
        } else if (levels[v1] > levels[v2]) {
            roots[v2] = v1;
        } else {
            roots[v2] = v1;
            levels[v1]++;
        }
    }

    static int find(int v) {
        while (roots[v] != v)
            v = roots[v];
        return v;
    }

}
