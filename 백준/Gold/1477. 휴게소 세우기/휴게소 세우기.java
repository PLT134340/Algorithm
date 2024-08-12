import java.util.Arrays;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int l = scanner.nextInt();
        int[] position = new int[n + 2];

        for (int i = 0; i < n; i++)
            position[i] = scanner.nextInt();
        position[n] = 0;
        position[n + 1] = l;
        Arrays.sort(position);

        int start = 1;
        int end = l;

        while (start < end) {
            int mid = (start + end) / 2;
            int count = 0;

            for (int i = 1; i < n + 2; i++) {
                int sub = position[i] - position[i - 1];
                count += sub / mid;
                if (sub % mid == 0)
                    count--;
            }

            if (count > m)
                start = mid + 1;
            else
                end = mid;
        }

        System.out.println(start);
    }
}