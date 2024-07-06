import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int[] nums = new int[n];
        
        for (int i = 0; i < n; i++)
            nums[i] = Integer.parseInt(line[i]);
            
        int minIdx = 0;
        for (int i = 1; i < n; i++)
            if (nums[minIdx] > nums[i])
                minIdx = i;
        
        boolean isSorted = true;
        for (int i = minIdx; i < n + minIdx - 1; i++)
            if (nums[i % n] > nums[(i + 1) % n]) {
                isSorted = false;
                break;
            }
            
        if (!isSorted)
            System.out.println(3);
        else if (nums[0] > nums[n - 1])
            System.out.println(2);
        else
            System.out.println(1);
    }   
}