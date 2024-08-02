import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++)
            if (isPrime[i])
                for (int j = 2; i * j <= n; j++)
                    isPrime[i * j] = false;

        boolean isReversed = false;
        Deque<Character> dq = new ArrayDeque<>();
        dq.offerLast('B');

        for (int i = 2; i <= n; i++)
            if (isPrime[i]) {
                if (isReversed)
                    if (dq.peekFirst() == 'B') {
                        dq.pollFirst();
                        dq.offerFirst('S');
                        dq.offerFirst('S');
                    } else
                        dq.offerFirst('S');
                else if (dq.peekLast() == 'B') {
                    dq.pollLast();
                    dq.offerLast('S');
                    dq.offerLast('S');
                } else
                    dq.offerLast('S');
            } else if (isReversed)
                dq.offerFirst('B');
            else
                dq.offerLast('B');

        int bCount = 0;
        int sCount = 0;

        for (char c : dq)
            if (c == 'B')
                bCount++;
            else
                sCount++;
                
        System.out.println(bCount + " " + sCount);
    }
}