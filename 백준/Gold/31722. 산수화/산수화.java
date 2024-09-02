import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.List;

class Main {

    static int n, m;
    static char[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        n = Integer.parseInt(line[0]);
        m = Integer.parseInt(line[1]);
        arr = new char[n][m];

        for (int i = 0; i < n; i++)
            arr[i] = br.readLine().toCharArray();

        int[][] leftMaxMountainSize = new int[n][m];
        int[][] rightMaxMountainSize = new int[n][m];
        int[] mountainCount = new int[n + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] != '#') {
                    leftMaxMountainSize[i][j] = 0;
                    continue;
                }
                if (i == 0 || j == 0) {
                    leftMaxMountainSize[i][j] = 1;
                    continue;
                }

                leftMaxMountainSize[i][j] = Math.min(leftMaxMountainSize[i - 1][j], leftMaxMountainSize[i][j - 1]) + 1;
            }

            for (int j = m - 1; j >= 0; j--) {
                if (arr[i][j] != '#') {
                    rightMaxMountainSize[i][j] = 0;
                    continue;
                }
                if (i == 0 || j == m - 1) {
                    rightMaxMountainSize[i][j] = 1;
                    continue;
                }

                rightMaxMountainSize[i][j] = Math.min(rightMaxMountainSize[i - 1][j], rightMaxMountainSize[i][j + 1]) + 1;
            }

            for (int j = 0; j < m; j++) {
                int min = Math.min(leftMaxMountainSize[i][j], rightMaxMountainSize[i][j]);
                mountainCount[min]++;
            }
        }

        int[][] maxLakeSize = new int[n][m];
        int[] lakeCount = new int[n + 1];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (arr[i][j] != '.') {
                    maxLakeSize[i][j] = 0;
                    continue;
                }
                if (i == n - 1 || j == m - 1) {
                    maxLakeSize[i][j] = 1;
                    continue;
                }

                int min = Collections.min(
                        List.of(maxLakeSize[i + 1][j], maxLakeSize[i][j + 1], maxLakeSize[i + 1][j + 1]));
                maxLakeSize[i][j] = min + 1;
            }

            for (int j = 0; j < m; j++)
                lakeCount[maxLakeSize[i][j]]++;
        }

        for (int i = n - 1; i >= 1; i--) {
            mountainCount[i] += mountainCount[i + 1];
            lakeCount[i] += lakeCount[i + 1];
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= n; i++)
            sb.append(mountainCount[i]).append(" ");
        sb.append("\n");

        for (int i = 1; i <= n; i++)
            sb.append(lakeCount[i]).append(" ");
        sb.append("\n");

        System.out.print(sb);
    }

}