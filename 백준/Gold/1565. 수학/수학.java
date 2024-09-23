import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int d = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        line = br.readLine().split(" ");
        long lcm = Integer.parseInt(line[0]);

        for (int i = 1; i < d; i++) {
            int num = Integer.parseInt(line[i]);
            lcm = leastCommonMultiple(lcm, num);
        }

        line = br.readLine().split(" ");
        long gcf = Integer.parseInt(line[0]);

        for (int i = 1; i < m; i++) {
            int num = Integer.parseInt(line[i]);
            gcf = greatestCommonFactor(gcf, num);
        }

        long i = 1;
        long result = 0;
        for (; i * i < gcf; i++)
            if (gcf % i == 0) {
                if (i % lcm == 0)
                    result++;
                if ((gcf / i) % lcm == 0)
                    result++;
            }
        if (i * i == gcf && i % lcm == 0)
            result++;
        System.out.println(result);
    }

    static long greatestCommonFactor(long num1, long num2) {
        if (num1 < num2) {
            long tmp = num2;
            num2 = num1;
            num1 = tmp;
        }

        while (num2 > 0) {
            long tmp = num1 % num2;
            num1 = num2;
            num2 = tmp;
        }

        return num1;
    }

    static long leastCommonMultiple(long num1, long num2) {
        long gcf = greatestCommonFactor(num1, num2);
        return num1 * num2 / gcf;
    }

}