import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int m = Integer.parseInt(br.readLine());

        while (m != 0) {
            String line = br.readLine();

            int left = 0;
            int right = 1;
            int max = 1;

            Map<Character, Integer> map = new HashMap<>();
            map.put(line.charAt(0), 1);

            while (right < line.length()) {
                char rightChar = line.charAt(right);

                while (map.size() == m && !map.containsKey(rightChar)) {
                    char leftChar = line.charAt(left);
                    map.compute(leftChar, (key, value) -> (value == 1) ? null : value - 1);
                    left++;
                }

                map.merge(rightChar, 1, Integer::sum);
                right++;

                if (max < right - left) {
                    max = right - left;
                }
            }

            System.out.println(max);

            m = Integer.parseInt(br.readLine());
        }
    }
}
