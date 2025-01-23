import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = n - 1; i > 1; i -= 2) {
            sb.append(i).append(" ").append(i - 1).append("\n");
        }

        int numOfOne = n / 2;
        int numOfZero = 0;

        while (numOfOne >= 2) {
            sb.append("1 1\n");
            numOfOne -= 2;
            numOfZero++;
        }

        while (numOfZero >= 2) {
            sb.append("0 0\n");
            numOfZero--;
        }

        if (numOfOne == 1) {
            if (numOfZero == 1) {
                sb.append("1 0\n");
            }

            System.out.println(n - 1);
            System.out.print(sb);
            System.out.println(n + " 1");
            return;
        }

        System.out.println(n);
        System.out.print(sb);
        System.out.println(n + " 0");
    }
}
