import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bufferedReader.readLine());

        int[] arr = new int[3];
        String[] line = bufferedReader.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            if (Integer.parseInt(line[i]) == 0)
                arr[0]++;
            else if (Integer.parseInt(line[i]) == 1)
                arr[1]++;
            else
                arr[2]++;
        }

        long result = 0;
        result += (long) arr[0] * (arr[0] - 1) / 2;
        result += (long) arr[0] * arr[1] * 2;
        result += (long) arr[0] * arr[2];
        System.out.println(result);
    }
}