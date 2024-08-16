import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Main {
    public static void main(String[] args) throws IOException {
        boolean[] isPrime = new boolean[10001];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= 10000; i++)
            if (isPrime[i])
                for (int j = 2; i * j <= 10000; j++)
                    isPrime[i * j] = false;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int p = Integer.parseInt(br.readLine());

        for (int i = 0; i < p; i++) {
            String[] line = br.readLine().split(" ");
            int order = Integer.parseInt(line[0]);
            int num = Integer.parseInt(line[1]);

//            int order = i + 1;
//            int num = i + 1;

            if (!isPrime[num]) {
                sb.append(order).append(" ").append(num).append(" NO\n");
                continue;
            }

            int rootSum = num;
            boolean isHappy = false;
            Set<Integer> set = new HashSet<>();

            do {
                set.add(rootSum);

                int newRootSum = 0;
                while (rootSum > 0) {
                    int digit = rootSum % 10;
                    newRootSum += digit * digit;
                    rootSum /= 10;

                }

                if (newRootSum == 1) {
                    isHappy = true;
                    break;
                }

                rootSum = newRootSum;
            } while (!set.contains(rootSum));

            if (isHappy)
                sb.append(order).append(" ").append(num).append(" YES\n");
            else
                sb.append(order).append(" ").append(num).append(" NO\n");
        }

        System.out.println(sb);
    }
}