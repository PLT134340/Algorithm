import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int q = Integer.parseInt(line[1]);

        line = br.readLine().split(" ");
        int[] score = new int[n];

        for (int i = 0; i < n; i++)
            score[i] = Integer.parseInt(line[i]);

        int[] mul1 = new int[n];
        for (int i = 0; i < n; i++)
            mul1[i] = score[i] * score[(i + 1) % n];

        int[] mul2 = new int[n];
        for (int i = 0; i < n; i++)
            mul2[i] = mul1[i] * mul1[(i + 2) % n];

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += mul2[i];

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        line = br.readLine().split(" ");

        for (int i = 0; i < q; i++) {
            int idx = Integer.parseInt(line[i]) - 1;

            for (int j = idx; j > idx - 4; j--) {
                mul2[(j + n) % n] = -mul2[(j + n) % n];
                sum += mul2[(j + n) % n] * 2;
            }

            bw.write(String.valueOf(sum));
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}