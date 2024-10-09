import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        String[] line = br.readLine().split(" ");
        int x = Integer.parseInt(line[0]);
        int y = Integer.parseInt(line[1]);
        int r = Integer.parseInt(line[2]);

        int a = 0;
        int b = 0;

        for (int i = 0; i < n; i++) {
            int t = Integer.parseInt(br.readLine());

            if (t > x - r && t < x + r)
                a++;
            else if (t == x - r || t == x + r)
                b++;
        }

        System.out.println(a + " " + b);
    }
}
