import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        int arr[] = new int[1000001];
        for (int i = 1; i <= 1000000; i++) {
            // System.out.println(String.format("i: %d", i));
            ArrayList<Integer> digit = new ArrayList<>();
            int tmp = i;

            while (tmp > 0) {
                digit.add(tmp % 10);
                tmp /= 10;
            }

            if (digit.size() < 3) {
                arr[i] = arr[i - 1];
                continue;
            }

            int idx = 1;
            while (idx < digit.size() && digit.get(idx - 1) < digit.get(idx))
                idx++;

            if (idx == 1 || idx == digit.size()) {
                arr[i] = arr[i - 1];
                continue;
            }

            while (idx < digit.size() && digit.get(idx - 1) > digit.get(idx))
                idx++;

            if (idx < digit.size())
                arr[i] = arr[i - 1];
            else
                arr[i] = arr[i - 1] + 1;
        }

        for (int i = 0; i < t; i++) {
            String[] line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);

            bw.write(String.valueOf(arr[b] - arr[a - 1]));
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}