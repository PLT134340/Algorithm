import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        for (int k = 0; k < t; k++) {
            String[] line = br.readLine().split(" ");

            int m = Integer.parseInt(line[0]);
            int n = Integer.parseInt(line[1]);
            BigInteger[] arr = new BigInteger[m];

            Arrays.fill(arr, BigInteger.ONE);

            for (int i = 0; i < n; i++) {
                line = br.readLine().split(" ");
                for (int j = 0; j < m; j++) {
                    int num = Integer.parseInt(line[j]);
                    arr[j] = arr[j].multiply(BigInteger.valueOf(num));
                }
            }

            int idx = 0;

            for (int i = 1; i < m; i++)
                if (arr[idx].compareTo(arr[i]) <= 0)
                    idx = i;

            System.out.println(idx + 1);
        }
    }
}