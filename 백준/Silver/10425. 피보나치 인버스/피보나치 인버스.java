import java.io.*;

class Main {
    
    static long MOD = 1_000_000_000_000_000L;
    
    public static void main(String[] args) throws IOException {
        long[] fib = new long[100001];
        fib[1] = 1;
        for (int i = 2; i <= 100000; i++)
            fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < t; i++) {
            String line = br.readLine();
            
            int len = line.length();
            if (len > 15)
                line = line.substring(len - 15);
                
            long num = Long.parseLong(line);
            
            if (num == 1) {
                System.out.println(2);
                continue;
            }
            
            int j = 0;
            while (fib[j] != num)
                j++;
            System.out.println(j);
        }
    }   
}