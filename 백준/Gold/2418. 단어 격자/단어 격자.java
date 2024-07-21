import java.util.*;

class Main {

    static int[] dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int[] dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int h = scanner.nextInt();
        int w = scanner.nextInt();
        int l = scanner.nextInt();

        String[] matrix = new String[h];
        for (int i = 0; i < h; i++)
            matrix[i] = scanner.next();

        String word = scanner.next();

        long dp[][][] = new long[h][w][l];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (matrix[i].charAt(j) == word.charAt(0))
                    dp[i][j][0] = 1;

        for (int k = 1; k < l; k++)
            for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                    if (matrix[i].charAt(j) == word.charAt(k))
                        for (int way = 0; way < 8; way++) {
                            int prevY = i + dy[way];
                            int prevX = j + dx[way];

                            if (prevY >= 0 && prevY < h && prevX >= 0 && prevX < w)
                                dp[i][j][k] += dp[prevY][prevX][k - 1];
                        }

        long result = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                result += dp[i][j][l - 1];
        System.out.println(result);
        
        // System.out.println();
        // for (int k = 0; k < l; k++) {
        //     for (int i = 0; i < h; i++) {
        //         for (int j = 0; j < w; j++) {
        //             System.out.print(dp[i][j][k] + " ");
        //         }
        //         System.out.println();
        //     }
        //     System.out.println();
        // }
    }

}