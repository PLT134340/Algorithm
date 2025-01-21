import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        char prevChar = str.charAt(0);

        if (str.equals("S") || str.equals("A")) {
            System.out.println(2);
            return;
        } else if (str.equals("SA") || str.equals("AK")) {
            System.out.println(2);
            return;
        } else if (str.equals("AA")) {
            System.out.println(4);
            return;
        }

        int index = 1;
        int removeNum = 0;

        while (index < str.length()) {
            if (prevChar == 'K' && str.charAt(index) == 'S') {
                prevChar = 'S';
            } else if (prevChar == 'S' && str.charAt(index) == 'A') {
                prevChar = 'A';
            } else if (prevChar == 'A' && str.charAt(index) == 'K') {
                prevChar = 'K';
            } else {
                removeNum++;
            }

            index++;
        }

        System.out.println(removeNum * 2);
    }
}
