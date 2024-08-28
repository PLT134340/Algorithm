import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int l = scanner.nextInt();
        boolean isSatisfied = false;
        StringBuilder sb = new StringBuilder();

        while (!isSatisfied && l <= 100) {
            int start;
            if (l % 2 == 0) {
                int div = n / l;

                if ((long) (div + div + 1) * l / 2 != n) {
                    l++;
                    continue;
                }

                start = div - l / 2 + 1;
            } else {
                int div = n / l;

                if (div * l != n) {
                    l++;
                    continue;
                }

                start = div - l / 2;
            }

            if (start < 0) {
                l++;
                continue;
            }

            isSatisfied = true;
            for (int i = 0; i < l; i++)
                sb.append(start + i).append(" ");
        }

        if (!isSatisfied)
            sb.append(-1);

        System.out.println(sb);
    }
}