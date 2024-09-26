import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        if (n == 0) {
            System.out.println(1);
            return;
        }

        int[] arr = new int[n + 1];
        arr[0] = arr[1] = 1;

        for (int i = 2; i <= n; i++) {
            int result = 1;
            boolean isEnd = false;

            while (!isEnd) {
                isEnd = true;
                for (int k = 1; i - 2 * k >= 0; k++)
                    if (2 * arr[i - k] == arr[i - 2 * k] + result) {
                        result++;
                        isEnd = false;
                        break;
                    }
            }

            arr[i] = result;
        }

        System.out.println(arr[n]);
    }
}