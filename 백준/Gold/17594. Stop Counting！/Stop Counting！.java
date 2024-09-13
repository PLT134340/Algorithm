import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(line[i]);

        double max = 0;
        double sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            double div = sum / (i + 1);
            max = Math.max(max, div);
        }

        sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            double div = sum / (n - i);
            max = Math.max(max, div);
        }

        System.out.println(max);
    }
}