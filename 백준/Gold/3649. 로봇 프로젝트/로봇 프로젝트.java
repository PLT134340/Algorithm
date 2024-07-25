import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String line = "";
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        while ((line = br.readLine()) != null) {
            int x = Integer.parseInt(line);
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];            
            
            for (int i = 0; i < n; i++)
                arr[i] = Integer.parseInt(br.readLine());
            
            Arrays.sort(arr);
            int left = 0;
            int right = n - 1;
            boolean isEnd = false;
            
            while (left < right && !isEnd) {
                int sum = arr[left] + arr[right];
                int product = x * 10_000_000;
                if (sum == product) {
                    bw.write("yes " + arr[left] + " " + arr[right]);
                    bw.newLine();
                    isEnd = true;
                } else if (sum < product)
                    left++;
                else
                    right--;
            }
            
            if (!isEnd) {
                bw.write("danger");
                bw.newLine();
            }
        }
        
        bw.flush();
        bw.close();
    }   
}