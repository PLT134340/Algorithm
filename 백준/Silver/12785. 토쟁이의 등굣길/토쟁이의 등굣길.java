import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static final int MOD = 1_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int w = Integer.parseInt(line[0]);
        int h = Integer.parseInt(line[1]);

        line = br.readLine().split(" ");
        int x = Integer.parseInt(line[0]);
        int y = Integer.parseInt(line[1]);

        int[][] dp = new int[h][w];
        for (int i = 0; i < h; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < w; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < h; i++) {
            for (int j = 1; j < w; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }

        long answer = ((long)dp[y - 1][x - 1] * dp[h - y][w - x]) % MOD;
        System.out.println(answer);
    }
    
}
