
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        long k = Long.parseLong(line[1]);
        
        line = br.readLine().split(" ");
        int[] arr = new int[n];
        
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(line[i]);
        
        long left = 1;
        long right = 10_000_000_000L;
        
        while (left < right) {
            long mid = (left + right) / 2;
            
            long sum = 0;
            for (int i = 0; i < n - 1; i++) {
                int sub = arr[i + 1] - arr[i];
                if (sub >= mid)
                    sum += mid * (mid + 1) / 2;
                else
                    sum += sub * (mid + mid - sub + 1) / 2;
            }
            sum += mid * (mid + 1) / 2;
            
            if (sum < k)
                left = mid + 1;
            else
                right = mid;
        }
        
        System.out.println(left);
    }
}