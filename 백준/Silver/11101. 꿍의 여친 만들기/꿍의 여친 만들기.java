import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(",");
            Map<String, Integer> map = new HashMap<>();
            
            for (int j = 0; j < line.length; j++) {
                String[] pair = line[j].split(":");
                map.put(pair[0], Integer.parseInt(pair[1]));
            }
            
            // for (Map.Entry<String, Integer> entry : map.entrySet())
            //     System.out.print(entry.getKey() + ":" + entry.getValue() + " ");
            // System.out.println();
            
            line = br.readLine().split("\\|");
            int min = Integer.MAX_VALUE;
            
            for (int j = 0; j < line.length; j++) {
                String[] condition = line[j].split("&");
                int max = 0;
                
                for (int k = 0; k < condition.length; k++) {
                    int value = map.get(condition[k]);
                    if (max < value)
                        max = value;
                }
                
                if (min > max)
                    min = max;
            }
            
            System.out.println(min);
        }
    }   
}