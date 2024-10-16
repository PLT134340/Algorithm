import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);

        line = br.readLine().split(" ");
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(line[i]);
        }

        int count = 0;
        for (int i = n - 1; i > 0 && count < k; i--) {
            int maxIndex = 0;
            for (int j = 1; j <= i; j++) {
                if (arr[maxIndex] < arr[j])
                    maxIndex = j;
            }

            if (maxIndex == i)
                continue;

            int tmp = arr[maxIndex];
            arr[maxIndex] = arr[i];
            arr[i] = tmp;
            count++;
        }

        if (count < k) {
            System.out.println(-1);
            return;
        }

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
