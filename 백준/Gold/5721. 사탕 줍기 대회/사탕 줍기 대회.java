import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        int m = Integer.parseInt(line[0]);
        int n = Integer.parseInt(line[1]);
        StringBuilder sb = new StringBuilder();

        while (!(m == 0 && n == 0)) {
            int[] row = new int[m + 1];

            for (int i = 1; i <= m; i++) {
                line = br.readLine().split(" ");
                int[] col = new int[n + 1];

                for (int j = 1; j <= n; j++)
                    col[j] = Integer.parseInt(line[j - 1]);

                for (int j = 3; j <= n; j++)
                    col[j] = Math.max(col[j - 3], col[j - 2]) + col[j];

                row[i] = Math.max(col[n - 1], col[n]);
            }

            for (int i = 3; i <= m; i++)
                row[i] = Math.max(row[i - 3], row[i - 2]) + row[i];

            sb.append(Math.max(row[m - 1], row[m])).append("\n");

            line = br.readLine().split(" ");

            m = Integer.parseInt(line[0]);
            n = Integer.parseInt(line[1]);
        }

        System.out.print(sb);
    }
}