import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        int[][] arr = new int[n + 3][n + 4];

        for (int i = 0; i < m; i++) {
            line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);
            int x = Integer.parseInt(line[2]);

            arr[a][b]++;
            arr[a][b + 1]--;
            arr[a + x + 2][b + 1]++;
            arr[a + x + 1][b]--;
            arr[a + x + 1][b + x + 2]++;
            arr[a + x + 2][b + x + 2]--;
        }

        for (int i = 1; i <= n + 2; i++)
            for (int j = 1; j <= n + 3; j++)
                arr[i][j] += arr[i][j - 1];

        for (int i = 1; i <= n + 3; i++)
            for (int j = 1; j <= n + 2; j++)
                arr[j][i] += arr[j - 1][i];

        for (int i = 0; i <= n + 2; i++)
            for (int j = 1; j <= n + 2 - i; j++)
                arr[i + j][1 + j] += arr[i + j - 1][j];

        int count = 0;
        for (int i = 0; i < n + 3; i++)
            for (int j = 0; j < n + 4; j++)
                if (arr[i][j] > 0)
                    count++;

        System.out.println(count);
    }
}