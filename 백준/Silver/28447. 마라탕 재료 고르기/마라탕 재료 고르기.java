import java.util.*;

class Main {

    static int n, k;
    static int[][] synergy;
    static ArrayList<Integer> containedIdx = new ArrayList<>();
    static int result = 0;
    static int max = Integer.MIN_VALUE;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        k = scanner.nextInt();

        synergy = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                synergy[i][j] = scanner.nextInt();
        
        recurs(0);
        
        System.out.println(max);
    }

    static void recurs(int level) {
        if (containedIdx.size() == k) {
            if (max < result)
                max = result;
            return;
        }
        if (level == n)
            return;
        
        int sum = 0;
        containedIdx.add(level);
        for (int val : containedIdx)
            sum += synergy[level][val];
        result += sum;
        recurs(level + 1);
        
        containedIdx.remove(containedIdx.size() - 1);
        result -= sum;
        recurs(level + 1);
    }

}