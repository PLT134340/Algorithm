import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        Deque<Integer> dq = new ArrayDeque<>();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            int count = 0;
            
            for (int j = 1; j <= 12; j++) {
                int num = Integer.parseInt(line[j]);
                
                if (dq.isEmpty()) {
                    if (num == 0)
                        continue;
                    dq.offerLast(num);
                } else if (dq.peekLast() < num)
                    dq.offerLast(num);
                else if (dq.peekLast() > num) {
                    while (!dq.isEmpty() && dq.peekLast() > num) {
                        dq.pollLast();
                        count++;
                    }
                    j--;
                }
            }
                
            bw.write(line[0] + " " + count);
            bw.newLine();
        }
        
        bw.flush();
        bw.close();
    }   
}