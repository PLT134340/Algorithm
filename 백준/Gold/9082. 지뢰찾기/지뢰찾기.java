import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split("");
            int[] num = new int[n];

            for (int j = 0; j < n; j++)
                num[j] = Integer.parseInt(line[j]);

            String[] arr = br.readLine().split("");
            int result = 0;

            for (int j = 0; j < n; j++)
                if (arr[j].equals("*")) {
                    if (j > 0)
                        num[j - 1]--;
                    num[j]--;
                    if (j < n - 1)
                        num[j + 1]--;
                    result++;
                }

            if (arr[0].equals("#"))
                if (num[0] > 0 && num[1] > 0) {
                    num[0]--;
                    num[1]--;
                    result++;
                }

            for (int j = 1; j < n - 1; j++)
                if (arr[j].equals("#"))
                    if (num[j - 1] > 0 && num[j] > 0 && num[j + 1] > 0) {
                        num[j - 1]--;
                        num[j]--;
                        num[j + 1]--;
                        result++;
                    }

            if (arr[n - 1].equals("#"))
                if (num[n - 2] > 0 && num[n - 1] > 0) {
                    num[n - 2]--;
                    num[n - 1]--;
                    result++;
                }

//            for (int j = 0; j < n; j++)
//                sb.append(num[j]).append(" ");
//            sb.append("\n");
//            for (int j = 0; j < n; j++)
//                sb.append(arr[j]).append(" ");
//            sb.append("\n");
            sb.append(result).append("\n");
        }

        System.out.print(sb);
    }
}