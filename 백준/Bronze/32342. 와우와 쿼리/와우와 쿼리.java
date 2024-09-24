import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int q = scanner.nextInt();

        for (int i = 0; i < q; i++) {
            String s = scanner.next();
            int result = 0;

            for (int j = 0; j <= s.length() - 3; j++)
                if (s.substring(j, j + 3).equals("WOW"))
                    result++;

            System.out.println(result);
        }
    }
}
