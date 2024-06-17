import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        int w = scanner.nextInt();
        
        int[][] dp = new int[t + 1][w + 1];
        for (int i = 1; i <= t; i++) {
            int num = scanner.nextInt();
            
            if (num == 1)
                dp[i][0] = dp[i - 1][0] + 1;
            else
                dp[i][0] = dp[i - 1][0];
            
            if (num == 1)
                for (int j = 1; j <= i && j <= w; j++)
                    if (j % 2 == 0)
                        dp[i][j] = Math.max(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
                    else
                        dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
            else
                for (int j = 1; j <= i && j <= w; j++)
                    if (j % 2 == 1) 
                        dp[i][j] = Math.max(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
                    else
                        dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
        }
        
        // for (int i = 0; i <= t; i++) {
        //     for (int j = 0; j <= w; j++)
        //         System.out.print(dp[i][j] + " ");
        //     System.out.println();
        // }
        System.out.println(dp[t][w]);
    }   
}