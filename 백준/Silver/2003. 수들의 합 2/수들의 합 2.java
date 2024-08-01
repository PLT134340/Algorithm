import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        long m = Long.parseLong(line[1]);
        
        line = br.readLine().split(" ");
        long[] sum = new long[n + 1];
        
        for (int i = 1; i <= n; i++) 
            sum[i] = sum[i - 1] + Integer.parseInt(line[i - 1]);
            
        int count = 0;
        
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                if (sum[i] - sum[j] == m)
                    count++;
        
        System.out.println(count);
    }   
}