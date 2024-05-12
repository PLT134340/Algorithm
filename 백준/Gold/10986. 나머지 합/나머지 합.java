import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        int sum = 0;
        long result = 0;
        int[] nums = new int[m];
        nums[0]++;
        line = br.readLine().split(" ");

        for (int i = 0; i < n; i++) {
            sum += Integer.parseInt(line[i]);
            sum %= m;
            result += nums[sum]++;
        }
        
        System.out.println(result);
    }
}