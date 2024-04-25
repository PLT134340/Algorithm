import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        final int MOD = 1000000007;
        
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        int u = scanner.nextInt();
        
        int[] dp = new int[u + u % 2 + 1];
        dp[1] = dp[2] = 1;
        
        for (int i = 3; i <= u; i += 2)
            dp[i + 1] = dp[i] = (int)((long)dp[i - 1] * 26 % MOD);
        
        // for (int i = 1; i <= u; i++)
        //     System.out.println(dp[i]);
        
        int result = 0;
        for (int i = l; i <= u; i++)
            result = (result + dp[i]) % MOD;
        
        if (l == 1 && u == 1 || l == 2)
            System.out.println("H");
        else
            System.out.println("A");
        System.out.println(result);
    }
}