import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        int r = Integer.parseInt(line[2]);
        
        line = br.readLine().split(" ");
        int[] pos = new int[n];
        for (int i = 0; i < n; i++)
            pos[i] = Integer.parseInt(line[i]);
        Arrays.sort(pos);
            
        line = br.readLine().split(" ");
        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 0; i < m; i++) {
            int height = Integer.parseInt(line[i]);
            set.add(height);
        }
        
        int max = 0;
        
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++) {
                int length = pos[j] - pos[i];
                Integer maxHeight = set.floor(r * 2 / length);
                
                // System.out.println(String.format("length: %d, maxHeight: %d", length, maxHeight));
                
                if (maxHeight == null)
                    continue;
                else if (max < length * maxHeight)
                    max = length * maxHeight;
            }
            
        if (max > 0)
            System.out.println(String.format("%.1f", (double)max / 2));
        else
            System.out.println(-1);
    }   
}