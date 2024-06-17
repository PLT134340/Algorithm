import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String aStr = scanner.next();
        String bStr = scanner.next();

        int aStart = 2;
        int bStart = 2;

        for (int i = 0; i < aStr.length(); i++) {
            char c = aStr.charAt(i);
            int numeral;

            if (c >= '0' && c <= '9')
                numeral = (int) (c - '0') + 1;
            else
                numeral = (int) (c - 'a') + 11;

            if (aStart < numeral)
                aStart = numeral;
        }
        for (int i = 0; i < bStr.length(); i++) {
            char c = bStr.charAt(i);
            int numeral;

            if (c >= '0' && c <= '9')
                numeral = (int) (c - '0') + 1;
            else
                numeral = (int) (c - 'a') + 11;

            if (bStart < numeral)
                bStart = numeral;
        }

        long matrix[][] = new long[2][37];
        Arrays.fill(matrix[0], -1L);
        Arrays.fill(matrix[1], -1L);

        for (int i = aStart; i <= 36; i++) {
            matrix[0][i] = 0;
            long digit = 1;

            for (int j = aStr.length() - 1; j >= 0; j--) {
                char c = aStr.charAt(j);
                int numeral;

                if (c >= '0' && c <= '9')
                    numeral = (int) (c - '0');
                else
                    numeral = (int) (c - 'a') + 10;

                matrix[0][i] += digit * numeral;
                digit *= i;

                if (matrix[0][i] < 0) {
                    matrix[0][i] = -1;
                    break;
                }
            }
        }
        for (int i = bStart; i <= 36; i++) {
            matrix[1][i] = 0;
            long digit = 1;

            for (int j = bStr.length() - 1; j >= 0; j--) {
                char c = bStr.charAt(j);
                int numeral;

                if (c >= '0' && c <= '9')
                    numeral = (int) (c - '0');
                else
                    numeral = (int) (c - 'a') + 10;

                matrix[1][i] += digit * numeral;
                digit *= i;

                if (matrix[1][i] < 0) {
                    matrix[1][i] = -1;
                    break;
                }
            }
        }

        int count = 0;
        int a = 0;
        int b = 0;

        for (int i = aStart; i <= 36; i++)
            for (int j = bStart; j <= 36; j++)
                if (i != j && matrix[0][i] != -1 && matrix[0][i] == matrix[1][j]) {
                    count++;
                    a = i;
                    b = j;
                }

        if (count > 1)
            System.out.println("Multiple");
        else if (count == 0)
            System.out.println("Impossible");
        else
            System.out.println(matrix[0][a] + " " + a + " " + b);
    }
}