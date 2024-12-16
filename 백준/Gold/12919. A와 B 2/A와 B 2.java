import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        String t = br.readLine();

        Set<String> set = new HashSet<>();
        Deque<String> deque = new ArrayDeque<>();
        deque.add(t);

        while (!deque.isEmpty()) {
            String str = deque.pollFirst();

            if (str.equals(s)) {
                System.out.println(1);
                return;
            } else if (set.contains(str)) {
                continue;
            }
            set.add(str);

            if (str.length() == 1) {
                continue;
            }
            
            if (str.charAt(str.length() - 1) == 'A') {
                deque.offerLast(str.substring(0, str.length() - 1));
            }
            if (str.charAt(0) == 'B') {
                StringBuilder sb = new StringBuilder(str.substring(1)).reverse();
                deque.offerLast(sb.toString());
            }
        }

        System.out.println(0);
    }
}
