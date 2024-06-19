import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        
        long[][] dp = new long[2][n];
        
        for (int i = 0; i < 2; i++) {
            line = br.readLine().split(" ");
            for (int j = 0; j < n; j++)
                dp[i][j] = Long.parseLong(line[j]);
        }
        
        for (int i = 1; i < n; i++)
            for (int j = 0; j < 2; j++) {
                if (dp[j][i - 1] < dp[1 - j][i - 1] + k)
                    dp[j][i] += dp[j][i - 1];
                else
                    dp[j][i] += dp[1 - j][i - 1] + k;
            }
            
        System.out.println(Math.min(dp[0][n - 1], dp[1][n - 1]));
        
        // for (int i = 0; i < 2; i++) {
        //     for (int j = 0; j < n; j++)
        //         System.out.print(dp[i][j] + " ");
        //     System.out.println();
        // }
    }   
}