import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static final int MOD = 1_000_000_009;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] dp = new int[100_001][3];
        dp[1][0] = 1;
        dp[2][1] = 1;
        dp[3][0] = dp[3][1] = dp[3][2] = 1;

        for (int i = 4; i <= 100_000; i++) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
            dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % MOD;
            dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % MOD;
        }

        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());

            int result = (dp[n][0] + dp[n][1]) % MOD;
            result = (result + dp[n][2]) % MOD;

            sb.append(result).append("\n");
        }

        System.out.print(sb);
    }
}
