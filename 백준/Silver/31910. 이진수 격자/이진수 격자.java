import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        long dp[][] = new long[n + 1][n + 1];
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                int num = scanner.nextInt();
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]) * 2 + num;
            }
        System.out.println(dp[n][n]);
    }
}