import java.util.*;

class Main {
    
    static final int MOD = 1000000007;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // String s = scanner.nextLine();
        
        int dp[][] = new int[n + 1][k + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= i && j <= k; j++)
                if (j == 0 || j == n)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= i && j <= k; j++)
        //         System.out.print(dp[i][j] + " ");
        //     System.out.println();
        // }
        
        int result = dp[n][k];
        for (int i = 1; i < k; i++)
            result  = result * 2 % MOD;
        System.out.println(result);
    }   
    
}