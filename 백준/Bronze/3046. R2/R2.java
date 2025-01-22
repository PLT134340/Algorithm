import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int r1 = Integer.parseInt(line[0]);
        int s = Integer.parseInt(line[1]);

        System.out.println(s * 2 - r1);
    }
}
