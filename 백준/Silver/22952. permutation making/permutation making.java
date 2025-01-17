import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        if (n == 1) {
            System.out.println(1);
            return;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 1; i < n / 2; i++) {
            sb.append(i).append(" ").append(n - i).append(" ");
        }
        if (n % 2 == 0) {
            sb.append(n / 2);
        } else {
            sb.append(n / 2).append(" ").append(n / 2 + 1);
        }
        sb.append(" ").append(n);

        System.out.println(sb);
    }
}
