import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t; i++) {
            String[] line = br.readLine().split(" ");
            int n = Integer.parseInt(line[0]);
            int m = Integer.parseInt(line[1]);
            int k = Integer.parseInt(line[2]);

            if (n > 1 && m * k == 1) {
                sb.append(-1).append("\n");
                continue;
            }

            int count = 0;

            while (n > 0) {
                n -= m * k;
                count++;

                if (n <= 0)
                    break;

                n++;
                count++;
            }

            sb.append(count).append("\n");
        }

        System.out.print(sb);
    }
}
