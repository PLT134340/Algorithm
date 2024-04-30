import java.util.*;
import java.io.*;

class Main {
    static int MOD = 1_000_000_007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        
        String[] line = br.readLine().split(" ");
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(line[i]);
        
        Arrays.sort(arr);
        
        long sum  = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += sum + arr[i];
            sum %= MOD;
        }
        
        System.out.println(sum);
    }
}