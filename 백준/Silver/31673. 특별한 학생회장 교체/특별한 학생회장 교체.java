import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        
        line = br.readLine().split(" ");
        ArrayList<Integer> arrayList = new ArrayList<>();
        long total = 0;
        
        for (int i = 0; i < n; i++) {
            arrayList.add(Integer.parseInt(line[i]));
            total += arrayList.get(i);
        }
            
        arrayList.sort(Comparator.reverseOrder());
        // for (int val : arrayList)
        //     System.out.print(val + " ");
        
        int i = 0;
        long sum = 0;
        while (sum < (total + 1) / 2)
            sum += arrayList.get(i++);
        
        System.out.println(m / (i + 1));
    }
}