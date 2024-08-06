import java.util.Scanner;

class Main {

    static int[][] arr = new int[10][10];
    static int[][] mask = new int[10][10];
    static int[] sizeCount = new int[6];
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                arr[i][j] = scanner.nextInt();

        recurs(0);

        if (answer == Integer.MAX_VALUE)
            System.out.println(-1);
        else
            System.out.println(answer);
    }

    static void recurs(int lv) {
        if (sizeCount[1] > 5 || sizeCount[2] > 5 || sizeCount[3] > 5 || sizeCount[4] > 5 || sizeCount[5] > 5)
            return;

        if (lv == 100) {
            int sum = 0;
            for (int i = 1; i <= 5; i++)
                sum += sizeCount[i];

            if (answer > sum)
                answer = sum;
                
            return;
        }

        int y = lv / 10;
        int x = lv % 10;

        if (arr[y][x] == 0 || mask[y][x] != 0) {
            recurs(lv + 1);
            return;
        }

        for (int length = 5; length > 0; length--)
            if (canCover(length, y, x)) {
                for (int i = y; i < y + length; i++)
                    for (int j = x; j < x + length; j++)
                        mask[i][j] = length;

                sizeCount[length]++;
                recurs(lv + 1);
                sizeCount[length]--;

                for (int i = y; i < y + length; i++)
                    for (int j = x; j < x + length; j++)
                        mask[i][j] = 0;
            }
    }

    static boolean canCover(int length, int y, int x) {
        if (y + length > 10 || x + length > 10)
            return false;

        for (int i = y; i < y + length; i++)
            for (int j = x; j < x + length; j++)
                if (arr[i][j] == 0 || mask[i][j] != 0)
                    return false;

        return true;
    }

    static class Pair {

        public int y;
        public int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    
}
