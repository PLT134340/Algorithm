import java.util.Scanner;

class Main {

    static final int INF = 100_000_000;
    static final int[] loop = {3, 5, 8};

    public static void main(String[] args) {
        int[][] dp = new int[1_000_001][3];
        for (int i = 1; i <= 1_000_000; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = INF;

        for (int i = 1; i <= 1_000_000; i++)
            for (int j = 0; j < loop.length; j++) {
                if (i - loop[j] < 0)
                    continue;

                int sum1 = 0;
                int sum2 = 0;

                for (int k = 0; k < 3; k++) {
                    sum1 += dp[i][k];
                    sum2 += dp[i - loop[j]][k];
                }

                if (sum1 < sum2 + 1)
                    continue;

                for (int k = 0; k < 3; k++)
                    dp[i][k] = dp[i - loop[j]][k];
                dp[i][j]++;
            }

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();

            if (dp[num][0] == INF) {
                sb.append("-1\n");
                continue;
            }

            for (int j = 0; j < 3; j++)
                sb.append(String.valueOf(loop[j]).repeat(Math.max(0, dp[num][j])));
            sb.append("\n");
        }

        System.out.print(sb);

//        for (int i = 1_000_000; i <= 1_000_000; i++)
//            System.out.printf("%d: %d %d %d\n", i, dp[i][0], dp[i][1], dp[i][2]);
    }

}