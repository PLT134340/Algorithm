import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String emoji = br.readLine();

        int colon = 0;
        int underBar = 0;

        for (int i = 0; i < emoji.length(); i++) {
            if (emoji.charAt(i) == ':') {
                colon++;
            } else if (emoji.charAt(i) == '_') {
                underBar++;
            }
        }

        System.out.println(emoji.length() + colon + underBar * 5);
    }
}
