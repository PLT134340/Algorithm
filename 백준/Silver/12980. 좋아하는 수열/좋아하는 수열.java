import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    private static int n;
    private static int[] arr;
    private static boolean[] isUsed;
    private static final ArrayList<Integer> zeroIdx = new ArrayList<>();
    private static final ArrayList<Integer> unUsedNum = new ArrayList<>();
    private static int result = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        n = Integer.parseInt(line[0]);
        int s = Integer.parseInt(line[1]);

        line = br.readLine().split(" ");
        arr = new int[n];
        isUsed = new boolean[n + 1];
        isUsed[0] = true;

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(line[i]);
            isUsed[arr[i]] = true;

            if (arr[i] == 0) {
                zeroIdx.add(i);
            }
        }

        for (int i = 0; i <= n; i++) {
            if (!isUsed[i]) {
                unUsedNum.add(i);
            }
        }

        int score = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] != 0 && arr[i] < arr[j]) {
                    score++;
                }
            }
        }

        int sub = s - score;
        recurs(0, sub);

        System.out.println(result);
    }

    static void recurs(int level, int score) {
        if (score < 0) {
            return;
        } else if (level == zeroIdx.size() && score == 0) {
            result++;
            return;
        }

        for (int num : unUsedNum) {
            if (isUsed[num]) {
                continue;
            }

            arr[zeroIdx.get(level)] = num;
            isUsed[num] = true;

            int plusScore = 0;
            for (int i = 0; i < zeroIdx.get(level); i++) {
                if (arr[i] < num) {
                    plusScore++;
                }
            }
            for (int i = zeroIdx.get(level) + 1; i < n; i++) {
                if (num < arr[i]) {
                    plusScore++;
                }
            }

            recurs(level + 1, score - plusScore);

            arr[zeroIdx.get(level)] = 0;
            isUsed[num] = false;
        }
    }
}
