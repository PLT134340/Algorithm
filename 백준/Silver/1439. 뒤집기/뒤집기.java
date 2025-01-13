import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();

        char firstChar = str.charAt(0);
        int answer = 0;

        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i - 1) != str.charAt(i) && str.charAt(i) != firstChar) {
                answer++;
            }
        }

        System.out.println(answer);
    }
}
