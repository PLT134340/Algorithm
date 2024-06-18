import java.io.*;

class Main {
    
    static int n;
    static int[] sum;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        
        line = br.readLine().split(" ");
        sum = new int[n + 1];
        
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + Integer.parseInt(line[i - 1]);
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        for (int i = 0; i < m; i++) {
            int t = Integer.parseInt(br.readLine());
            int idx = binarySearch(t) - 1;
            
            bw.write(String.valueOf(idx));
            bw.newLine();
        }
        
        bw.flush();
        bw.close();
    }   
    
    static int binarySearch(int val) {
        int start = 0;
        int end = n;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            if (sum[mid] > val)
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return start;
    }
    
}