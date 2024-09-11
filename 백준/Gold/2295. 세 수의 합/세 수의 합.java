import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(br.readLine());
        Arrays.sort(arr);

        Set<Integer> sum = new HashSet<>();
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                sum.add(arr[i] + arr[j]);

        for (int i = n - 1; i >= 0; i--)
            for (int j = n - 2; j >= 0; j--)
                if (sum.contains(arr[i] - arr[j])) {
                    System.out.println(arr[i]);
                    return;
                }
    }
}