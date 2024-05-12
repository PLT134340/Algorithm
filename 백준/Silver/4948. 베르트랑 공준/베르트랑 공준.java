import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        boolean isNotPrime[] = new boolean[246913];
        isNotPrime[0] = isNotPrime[1] = true;

        for (int i = 2; i * i <= 246912; i++)
            if (!isNotPrime[i])
                for (int j = 2; i * j <= 246912; j++)
                    isNotPrime[i * j] = true;

        // for (int i = 1; i <= 20; i++)
        //     System.out.println(i + ": " + !isNotPrime[i]);
        
        int n = scanner.nextInt();
        while (n != 0) {
            int result = 0;
            for (int i = n + 1; i <= 2 * n; i++)
                if (!isNotPrime[i])
                    result++;
            System.out.println(result);
            n = scanner.nextInt();
        }
    }
}