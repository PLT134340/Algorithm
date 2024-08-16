import java.util.Scanner;

class Main {

    static int INF = 1_000_000_000;

    static int n;
    static int[][] weight;
    static boolean[] isVisited;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        weight = new int[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                weight[i][j] = scanner.nextInt();
                if (weight[i][j] == 0)
                    weight[i][j] = INF;
            }

        isVisited = new boolean[n];

        for (int i = 0; i < n; i++) {
            isVisited[i] = true;
            recurs(0, i, 0, i);
            isVisited[i] = false;
        }

        System.out.println(min);
    }

    static void recurs(int lv, int start, int sum, int prevIdx) {
//        System.out.printf("lv=%d sum=%d prevIdx=%d\n", lv, sum, prevIdx);
        if (sum >= INF)
            return;

        if (lv == n - 1) {
            sum += weight[prevIdx][start];
            if (min > sum)
                min = sum;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isVisited[i])
                continue;

            isVisited[i] = true;
            recurs(lv + 1, start, sum + weight[prevIdx][i], i);
            isVisited[i] = false;
        }
    }

}