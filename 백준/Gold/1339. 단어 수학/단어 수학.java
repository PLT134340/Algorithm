import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            int figure = 1;

            for (int j = s.length() - 1; j >= 0; j--, figure *= 10)
                if (!map.containsKey(s.charAt(j)))
                    map.put(s.charAt(j), figure);
                else
                    map.put(s.charAt(j), map.get(s.charAt(j)) + figure);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        map.forEach((key, value) -> pq.offer(value));

        int digit = 9;
        int result = 0;

        while (!pq.isEmpty()) {
            result += pq.poll() * digit;
            digit--;
        }

        System.out.println(result);
    }
}