import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(":");

        int hour = Integer.parseInt(line[0]);
        int minute = Integer.parseInt(line[1]);

        int total = hour * 60 + minute;

        for (int i = 0; i < 120; i++)
            if (total >= 7 * 60 && total < 10 * 60
                    || total >= 15 * 60 && total < 19 * 60)
                total += 2;
            else
                total++;

        if (total >= 24 * 60)
            total -= 24 * 60;

        System.out.printf("%02d:%02d\n", total / 60, total % 60);
    }
}