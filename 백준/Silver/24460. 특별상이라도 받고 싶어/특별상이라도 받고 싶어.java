import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {

    static int n;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < n; j++)
                arr[i][j] = Integer.parseInt(line[j]);
        }

        System.out.println(recurs(n, 0, 0));
    }

    static int recurs(int length, int y, int x) {
        if (length == 1)
            return arr[y][x];

        int nextLength = length / 2;
        int[] numbers = new int[4];

        numbers[0] = recurs(nextLength, y, x);
        numbers[1] = recurs(nextLength, y + nextLength, x);
        numbers[2] = recurs(nextLength, y, x + nextLength);
        numbers[3] = recurs(nextLength, y + nextLength, x + nextLength);

        Arrays.sort(numbers);

        return numbers[1];
    }

}