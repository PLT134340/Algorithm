import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int[] arr = new int[3];

        boolean isAllEven = true;
        int mul = 1;

        for (int i = 0; i < 3; i++) {
            arr[i] = Integer.parseInt(line[i]);
            if (arr[i] % 2 == 1) {
                mul *= arr[i];
                isAllEven = false;
            }
        }

        if (isAllEven)
            System.out.println(arr[0] * arr[1] * arr[2]);
        else
            System.out.println(mul);
    }
}