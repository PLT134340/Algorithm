import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        
        long[] dp = new long[101];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 4;
        dp[5] = 5;
        dp[6] = 6;
        
        for (int i = 7; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j <= i - 3; j++)
                dp[i] = Math.max(dp[i], dp[j] * (i - j - 1));
        }
        System.out.println(dp[n]);
        
        // for (int i = 1; i <= n; i++)
        //     System.out.println(i + ": " + dp[i]);
    }   
}