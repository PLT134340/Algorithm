import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < 3; i++) {
            int n = Integer.parseInt(br.readLine());
            BigInteger sum = new BigInteger("0");

            for (int j = 0; j < n; j++) {
                BigInteger num = new BigInteger(br.readLine());
                sum = sum.add(num);
            }

            int sign = sum.compareTo(new BigInteger("0"));
            String result;
            if (sign == 0)
                result = "0";
            else if (sign > 0)
                result = "+";
            else
                result = "-";

            sb.append(result).append("\n");
        }

        System.out.print(sb);
    }
}