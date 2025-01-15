import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    static int n;
    static int[] prices;
    static ArrayList<ArrayList<Pair>> discounts;

    static boolean[] isPurchased;
    static int minPrice = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        prices = new int[n];

        String[] line = br.readLine().split(" ");

        for (int i = 0; i < n; i++) {
            prices[i] = Integer.parseInt(line[i]);
        }

        discounts = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            discounts.add(new ArrayList<>());
        }

        for (int i = 0; i < n; i++) {
            int m = Integer.parseInt(br.readLine());

            for (int j = 0; j < m; j++) {
                line = br.readLine().split(" ");
                int a = Integer.parseInt(line[0]) - 1;
                int d = Integer.parseInt(line[1]);

                discounts.get(i).add(new Pair(a, d));
            }
        }

        isPurchased = new boolean[n];

        for (int i = 0; i < n; i++) {
            dfs(0, i, 0);
        }

        System.out.println(minPrice);
    }

    static void dfs(int lv, int index, int sum) {
//        System.out.printf("lv=%d index=%d sum=%d\n", lv, index, sum);
        if (lv == n) {
            if (minPrice > sum) {
                minPrice = sum;
            }
            return;
        } else if (sum >= minPrice) {
            return;
        } if (isPurchased[index]) {
            return;
        }

        isPurchased[index] = true;
        int[] prevPrices = prices.clone();
        for (Pair p : discounts.get(index)) {
            prices[p.num] -= p.discount;
            if (prices[p.num] <= 0) {
                prices[p.num] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
//            System.out.printf("index=%d price=%d\n", index, prices[index]);
            dfs(lv + 1, i, sum + prices[index]);
        }

        prices = prevPrices.clone();
        isPurchased[index] = false;
    }

    static class Pair {
        public int num;
        public int discount;

        public Pair(int num, int discount) {
            this.num = num;
            this.discount = discount;
        }
    }

}
