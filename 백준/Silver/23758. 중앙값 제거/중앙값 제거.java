import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int[] arr = new int[n];
        
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(line[i]);
        
        Arrays.sort(arr);
        
        int count = 0;
        for (int i = 0; i <= (n - 1) / 2; i++)
            while (arr[i] > 1) {
                arr[i] >>= 1;
                count++;
            }
        System.out.println(count + 1);
    }   
}