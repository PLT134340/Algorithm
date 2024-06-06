import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        
        int[][] dp = new int[n + 1][m + 1];
        
        for (int i = 1; i <= n; i++) {
            line = br.readLine().split(" ");
            for (int j = 1; j <= m; j++) {
                int time = Integer.parseInt(line[j - 1]);
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]) + time;
            }
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 1; i <= n; i++)
            bw.write(dp[i][m] + " ");
        bw.flush();
        bw.newLine();
        bw.close();
    }   
}