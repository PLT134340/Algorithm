import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        
        String[] line = br.readLine().split(" ");
        int[] amount = new int[n];
        long sum = 0;
        for (int i = 0; i < n ; i++) {
            amount[i] = Integer.parseInt(line[i]);
            sum += amount[i];
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(sum));
        bw.newLine();
        
        boolean[] isOpen = new boolean[n];
        Arrays.fill(isOpen, true);
        int q = Integer.parseInt(br.readLine());
        for (int i = 0; i < q; i++) {
            line = br.readLine().split(" ");
            int idx = Integer.parseInt(line[1]) - 1;
            
            if (line[0].equals("1")) {
                int newAmount = Integer.parseInt(line[2]);
                if (isOpen[idx])
                    sum = sum - amount[idx] + newAmount;
                amount[idx] = newAmount;
            } else { 
                if (!isOpen[idx]) 
                    sum += amount[idx];
                else
                    sum -= amount[idx];
                isOpen[idx] = !isOpen[idx];
            }
            
            bw.write(String.valueOf(sum));
            bw.newLine();
        }
        
        bw.flush();
        bw.close();
    }   
}