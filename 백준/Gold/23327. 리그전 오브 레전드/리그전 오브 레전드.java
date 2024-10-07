import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int q = Integer.parseInt(line[1]);

        line = br.readLine().split(" ");
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(line[i]);
        }

        long[] sum = new long[n + 1];
        long[] squareSum = new long[n + 1];

        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + arr[i - 1];
            squareSum[i] = squareSum[i - 1] + (long) arr[i - 1] * arr[i - 1];
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < q; i++) {
            line = br.readLine().split(" ");
            int l = Integer.parseInt(line[0]);
            int r = Integer.parseInt(line[1]);

            long sectionSum = sum[r] - sum[l - 1];
            long sectionSquareSum = squareSum[r] - squareSum[l - 1];

            long result = (sectionSum * sectionSum - sectionSquareSum) / 2;

            sb.append(result).append("\n");
        }

        System.out.print(sb);
    }
}
