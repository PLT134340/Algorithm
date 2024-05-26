import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int k = scanner.nextInt();
        int n = scanner.nextInt();
        
        if (k == 0) {
            System.out.println(0);
            return;
        }
        
        long dp[][] = new long[64][129];
        dp[0][k] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 127; j++)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            dp[i][128] = dp[i - 1][127];
        } 
        
        long result = 0;
        for (int i = 1; i <= 128; i++)
            result += dp[n][i];
        System.out.println(result);
    }   
}