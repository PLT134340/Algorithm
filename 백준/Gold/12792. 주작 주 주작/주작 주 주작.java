import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    static final int size = 1_100_000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(line[i]) - 1;
            if (arr[i] == i) {
                System.out.println(-1);
                return;
            }
        }

        boolean[] isPrime = new boolean[size + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= size; i++)
            if (isPrime[i])
                for (int j = 2; i * j <= size; j++)
                    isPrime[i * j] = false;

        for (int i = 1_000_001; i <= size; i++)
            if (isPrime[i]) {
                System.out.println(i);
                return;
            }
    }
}