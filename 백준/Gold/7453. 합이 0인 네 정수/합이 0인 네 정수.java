import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][4];
        
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < 4; j++)
                arr[i][j] = Integer.parseInt(line[j]);
        }
        
        int idx = 0;
        int[] sum1 = new int[n * n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                sum1[idx++] = arr[i][0] + arr[j][1];
        idx = 0;
        int[] sum2 = new int[n * n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                sum2[idx++] = arr[i][2] + arr[j][3];
        Arrays.sort(sum1);
        Arrays.sort(sum2);
        
        long count = 0;
        int idx1 = 0;
        int idx2 = sum2.length - 1;
        
        while (idx1 < sum1.length && idx2 >= 0) {
            int sum = sum1[idx1] + sum2[idx2];
            if (sum == 0) {
                int upp1 = upperBound(sum1, sum1[idx1]);
                int low2 = lowerBound(sum2, sum2[idx2]);
                
                count += ((long)upp1 - idx1) * ((long)idx2 - low2 + 1);
                
                idx1 = upp1;
                idx2 = low2 - 1;
            } else if (sum < 0)
                idx1++;
            else
                idx2--;
        }
        
        System.out.println(count);
    }   
    
    static int lowerBound(int[] arr, int val) {
        int start = 0;
        int end = arr.length - 1;
        
        while (start < end) {
            int mid = (start + end) / 2;
            if (arr[mid] >= val)
                end = mid;
            else
                start = mid + 1;
        }
        
        return start;
    }
    
    static int upperBound(int[] arr, int val) {
        int start = 0;
        int end = arr.length - 1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] > val)
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return start;
    }
}