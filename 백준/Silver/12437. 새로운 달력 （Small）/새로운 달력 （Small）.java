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
            int totalMonth = Integer.parseInt(line[0]);
            int dayPerMonth = Integer.parseInt(line[1]);
            int dayPerWeek = Integer.parseInt(line[2]);

            int result = 0;
            int days = 0;

            for (int j = 0; j < totalMonth; j++) {
                days += dayPerMonth;

                while (days >= dayPerWeek) {
                    days -= dayPerWeek;
                    result++;
                }

                if (days == 0) {
                    continue;
                }
                result++;
            }

            sb.append("Case #").append(i + 1).append(": ").append(result).append("\n");
        }

        System.out.print(sb);
    }
}
