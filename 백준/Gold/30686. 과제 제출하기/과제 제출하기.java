import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class Main {

    static int m;
    static int[] time;
    static ArrayList<int[]> arrayList;
    static boolean[] isSolved;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        m = scanner.nextInt();
        time = new int[n];
        arrayList = new ArrayList<>();

        for (int i = 0; i < n; i++)
            time[i] = scanner.nextInt();

        for (int i = 0; i < m; i++) {
            int k = scanner.nextInt();

            arrayList.add(new int[k]);

            for (int j = 0; j < k; j++)
                arrayList.get(i)[j] = scanner.nextInt() - 1;
        }

        int[] expiredTime = new int[n];
        Arrays.fill(expiredTime, -1);
        isSolved = new boolean[m];

        recurs(0, 0, expiredTime);

        System.out.println(min);
    }

    static void recurs(int level, int usedKnowledgeCount, int[] expiredTime) {
//        System.out.printf("level: %d, count: %d, time: ", level, usedKnowledgeCount);
//        for (int t : expiredTime)
//            System.out.print(t + " ");
//        System.out.print(", solved: ");
//        for (boolean s : isSolved)
//            System.out.print(s + " ");
//        System.out.println();

        if (level == m) {
            if (min > usedKnowledgeCount) {
                min = usedKnowledgeCount;

//                System.out.printf("min: %d, ", usedKnowledgeCount);
//                for (int t : expiredTime)
//                    System.out.print(t + " ");
//                System.out.println();
            }
            return;
        }

        for (int i = 0; i < m; i++) {
            if (isSolved[i])
                continue;

            isSolved[i] = true;
            int newUsedKnowledgeCount = usedKnowledgeCount;
            int[] newExpiredTime = expiredTime.clone();

            for (int t : arrayList.get(i)) {
                if (newExpiredTime[t] >= level)
                    continue;

                newUsedKnowledgeCount++;
                newExpiredTime[t] = level + time[t] - 1;
            }
            recurs(level + 1, newUsedKnowledgeCount, newExpiredTime);

            isSolved[i] = false;
        }
    }

}