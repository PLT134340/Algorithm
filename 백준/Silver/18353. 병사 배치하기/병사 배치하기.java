import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] arr = new int[n];
        
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (arr[i] < arr[j] && dp[i] <= dp[j])
                    dp[i] = dp[j] + 1;
        }
        
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (max < dp[i])
                max = dp[i];
            // System.out.print(dp[i] + " ");
        }
        System.out.println(n - max);
    }   
}