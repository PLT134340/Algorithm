import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        String wheel = scanner.next();
        int m = scanner.nextInt();
        String target = scanner.next();

        int idx = 0;
        int total = 1;
        int length = 0;
        int limit = 0;

        while (limit <= n && length < m) {
            if (wheel.charAt(idx) == target.charAt(length)) {
                length++;
                limit = 0;
            }

            idx++;
            total++;
            if (idx == n)
                idx = 0;
            limit++;
        }
        
        if (length != m) 
            System.out.println(-1);
        else
            System.out.println(total - 1);
    }
}