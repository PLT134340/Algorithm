import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        boolean[] isNotPrime = new boolean[1001];
        isNotPrime[0] = isNotPrime[1] = true;

        for (int i = 2; i * i <= 1000; i++)
            if (!isNotPrime[i])
                for (int j = 2; i * j <= 1000; j++)
                    isNotPrime[i * j] = true;

        int a = scanner.nextInt();
        int b = scanner.nextInt();

        int yt = 0;
        for (int i = a; i <= b; i++)
            if (!isNotPrime[i])
                yt++;

        int c = scanner.nextInt();
        int d = scanner.nextInt();

        int yj = 0;
        for (int i = c; i <= d; i++)
            if (!isNotPrime[i])
                yj++;

        int common = 0;
        int start = a > c ? a : c;
        int end = b < d ? b : d;
        for (int i = start; i <= end; i++)
            if (!isNotPrime[i])
                common++;

        yt -= common / 2;
        yj -= common - common / 2;
        
        // System.out.println(yt);
        // System.out.println(yj);

        if (yt <= yj)
            System.out.println("yj");
        else
            System.out.println("yt");
    }
}