import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t; i++) {
            String[] line = br.readLine().split(" ");
            int n = Integer.parseInt(line[0]);
            int[] arr = new int[n + 1];
            int[] sum = new int[n + 1];

            for (int j = 1; j <= n; j++)
                arr[j] = Integer.parseInt(line[j]);

            Arrays.sort(arr);

            for (int j = 1; j <= n; j++)
                sum[j] = sum[j - 1] + arr[j];

//            for (int j = 1; j <= n; j++)
//                System.out.println(arr[j] + " " + sum[j]);

            long answer = 0;

            for (int j = 1; j <= n; j++) {
                int min = Integer.MAX_VALUE;
                for (int k = j; k <= n; k++) {
                    int addition = arr[k] * j - (sum[k] - sum[k - j]);
                    if (min > addition)
                        min = addition;
                }

                answer += min;
//                System.out.println(j + ": " + min);
            }

            sb.append(String.valueOf(answer)).append("\n");
        }

        System.out.print(sb);
    }
}