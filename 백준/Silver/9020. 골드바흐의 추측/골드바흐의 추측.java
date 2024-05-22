import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        boolean[] isNotPrime = new boolean[10001];
        isNotPrime[0] = isNotPrime[1] = true;
        
        for (int i = 2; i * i <= 10000; i++)
            if (!isNotPrime[i])
                for (int j = 2; i * j <= 10000; j++)
                    isNotPrime[i * j] = true;
                
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int[] result = {0, n};
            
            for (int j = 0; j <= n / 2; j++)
                if (!isNotPrime[j] && !isNotPrime[n - j] && result[1] - result[0] > n - j - j) {
                    result[0] = j;
                    result[1] = n - j;
                }
            
            System.out.println(String.format("%d %d", result[0], result[1]));
        }
    }   
}