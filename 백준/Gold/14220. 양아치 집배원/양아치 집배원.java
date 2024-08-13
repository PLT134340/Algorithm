import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {

    static int INF = 1_000_000_000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] length = new int[n][n];

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");

            for (int j = 0; j < n; j++) {
                int num = Integer.parseInt(line[j]);
                if (num == 0)
                    length[i][j] = INF;
                else
                    length[i][j] = num;
            }
        }

        int[][] dp = new int[n][n];

        for (int k = 1; k < n; k++)
            for (int i = 0; i < n; i++)
                    dp[k][i] = INF;

        for (int k = 1; k < n; k++)
            for (int i = 0; i < n; i++){
                int min = INF;
                for (int a = 0; a < n; a++) {
                    int sum = dp[k - 1][a] + length[a][i];
                    if (min > sum)
                        min = sum;
                }
                dp[k][i] = min;
            }

        int result = INF;
        for (int i = 0; i < n; i++)
            if (result > dp[n - 1][i])
                result = dp[n - 1][i];

        if (result == INF)
            System.out.println(-1);
        else
            System.out.println(result);
    }
}