import java.util.ArrayList;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        ArrayList<Long> dp = new ArrayList<>();
        dp.add(0L);

        for (int i = 0; i < t; i++) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();

            long dif = y - x;
            while (dp.get(dp.size() - 1) < dif)
                dp.add(dp.get(dp.size() - 1) + (dp.size() - 1) / 2 + 1);

            for (int j = 0; j < dp.size(); j++)
                if (dp.get(j) >= dif) {
                    System.out.println(j);
                    break;
                }
        }
    }
}