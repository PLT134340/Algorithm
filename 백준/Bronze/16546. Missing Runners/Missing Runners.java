import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");

        int sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += Integer.parseInt(line[i]);

        System.out.println(n * (n + 1) / 2 - sum);
    }
}