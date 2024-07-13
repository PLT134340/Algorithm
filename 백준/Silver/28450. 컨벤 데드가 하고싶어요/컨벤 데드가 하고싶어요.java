import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        long[][] dp = new long[n][m];
        
        for (int i = 0; i < n; i++) {
            line = br.readLine().split(" ");
            
            for (int j = 0; j < m; j++)
                dp[i][j] = Long.parseLong(line[j]);
        }
        
        for (int i = 1; i < n; i++)
            dp[i][0] += dp[i - 1][0];
        for (int i = 1; i < m; i++)
            dp[0][i] += dp[0][i - 1];
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                dp[i][j] += Math.min(dp[i - 1][j], dp[i][j - 1]);
        
        int h = Integer.parseInt(br.readLine());
        
        if (dp[n - 1][m - 1] > h)
            System.out.println("NO");
        else {
            System.out.println("YES");
            System.out.println(dp[n - 1][m - 1]);
        }
    }   
}