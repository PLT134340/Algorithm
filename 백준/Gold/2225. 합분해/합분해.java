import java.util.*;

class Main {
    
    static final int MOD = 1_000_000_000;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        int[][] dp = new int[n + 1][k + 1];
        
        for (int i = 0; i <= k; i++)
            dp[0][i] = 1;
        for (int i = 0; i <= n; i++)
            dp[i][1] = 1;
        
        for (int i = 1; i <= n; i++)
            for (int j = 2; j <= k; j++) 
                for (int l = 0; l <= i; l++) {
                    dp[i][j] += dp[l][j - 1];
                    dp[i][j] %= MOD;
                }
        
        System.out.println(dp[n][k]);
    }   
    
}