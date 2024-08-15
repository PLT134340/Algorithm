import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            String[] line = br.readLine().split(" ");

            int n = Integer.parseInt(line[0]);
            int x = Integer.parseInt(line[1]);

            double sum = 0;
            for (int j = 0; j < n; j++)
                sum += Double.parseDouble(br.readLine());

            int max = 0;
            int min = Integer.MAX_VALUE;

            for (int j = 0; j <= 100000; j++) {
                double total = sum * (100 + j) / 100;

                if ((total >= x && total < x + 1) || (total + 0.0099 >= x && total + 0.0099 < x + 1)) {
                    if (max < j)
                        max = j;
                    if (min > j)
                        min = j;
                }
            }

            System.out.println(min + " " + max);
        }
    }
}