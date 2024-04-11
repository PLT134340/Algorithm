import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        if (n == 2) {
            System.out.println("2 4");
            return;
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        long sum = (long)n * (n - 1);
        
        for (int i = 3; i <= 1000000; i += 2)
            if ((sum + i) % i == 0) {
                for (int j = 1; j < n; j++)
                    bw.write(String.valueOf(2 * j) + " ");
                bw.write(String.valueOf(i));
                break;
            }
        bw.newLine();        
        bw.flush();
        bw.close();
    }
}