import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        long result = 0;
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
            int l = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");

            int[] sum = new int[l + 1];

            for (int j = 1; j <= l; j++)
                sum[j] = sum[j - 1] + Integer.parseInt(line[j - 1]);

            int answer[] = { 0, 1 };

            for (int j = 1; j <= l; j++)
                for (int k = 0; k < j; k++)
                    if (sum[answer[1]] - sum[answer[0]] < sum[j] - sum[k]
                            || (sum[answer[1]] - sum[answer[0]] == sum[j] - sum[k]
                                    && answer[1] - answer[0] > j - k)
                            || (sum[answer[1]] - sum[answer[0]] == sum[j] - sum[k]
                                    && answer[1] - answer[0] == j - k
                                    && answer[0] > k)) {
                        answer[1] = j;
                        answer[0] = k;
                    }
            
            result += sum[answer[1]] - sum[answer[0]];
            sb.append((answer[0] + 1) + " " + answer[1] + "\n");
        }
        
        System.out.println(result);
        System.out.print(sb);
    }
}