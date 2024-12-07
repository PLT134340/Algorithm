import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t; i++) {
            String s = br.readLine();

            if (s.matches("(100+1+|01)+"))
                sb.append("YES\n");
            else
                sb.append("NO\n");
        }

        System.out.print(sb);
    }
}
