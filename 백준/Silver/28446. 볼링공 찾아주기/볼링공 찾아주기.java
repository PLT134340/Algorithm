import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(br.readLine());
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            
            if (line[0].equals("1")) {
                int val = Integer.parseInt(line[1]);
                int key = Integer.parseInt(line[2]);
                map.put(key, val);
            } else {
                int key = Integer.parseInt(line[1]);
                bw.write(String.valueOf(map.get(key)));
                bw.newLine();
            }
        }
        
        bw.flush();
        bw.close();
    }   
}