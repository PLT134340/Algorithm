import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] p = new int[n];
        String[] line = br.readLine().split(" ");

        for (int i = 0; i < n; i++)
            p[i] = Integer.parseInt(line[i]);

        long k = Long.parseLong(br.readLine());

        long answer = 0;

        for (int i = 0; i < n; i++) {
            long tmp = k;

            while (tmp >= p[i]) {
                tmp /= p[i];
                answer += tmp;
            }
        }

        System.out.println(answer);
    }
}