import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int q = Integer.parseInt(line[1]);
        
        line = br.readLine().split(" ");
        int[] arr = new int[n];
        
        for (int i = 0; i < n; i++)
           arr[i] = Integer.parseInt(line[i]);
        
        int start = 0;
        for (int i = 0; i < q; i++) {
            line = br.readLine().split(" ");
            
            int num[] = new int[line.length];
            for (int j = 0; j < line.length; j++)
                num[j] = Integer.parseInt(line[j]);
                
            if (num[0] == 1)
                arr[(start + num[1] - 1) % n] += num[2];
            else if (num[0] == 2) {
                start -= num[1];
                if (start < 0)
                    start += n;
            } else {
                start += num[1];
                if (start >= n)
                    start -= n;
            }
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = start; i < n; i++)
            bw.write(String.valueOf(arr[i]) + " ");
        for (int i = 0; i < start; i++)
            bw.write(String.valueOf(arr[i]) + " ");
        bw.newLine();
        bw.flush();
        bw.close();
    }   
}