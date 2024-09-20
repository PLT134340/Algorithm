import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main {

    static int n, k;
    static int result = 0;
    static ArrayList<ArrayList<String>> topics = new ArrayList<>();
    static Map<String, Integer> map = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        k = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            topics.add(new ArrayList<>());
            int t = scanner.nextInt();

            for (int j = 0; j < t; j++) {
                String topic = scanner.next();
                topics.get(i).add(topic);
            }
        }

        recurs(0, 0);

        System.out.println(result);
    }

    static void recurs(int idx, int num) {
        if (num == k) {
            for (int value : map.values())
                if (value > k / 2)
                    return;

            result++;
            return;
        }
        if (idx == n)
            return;

        for (String topic : topics.get(idx))
            if (map.containsKey(topic))
                map.put(topic, map.get(topic) + 1);
            else
                map.put(topic, 1);
        recurs(idx + 1, num + 1);
        for (String topic : topics.get(idx))
            if (map.get(topic) == 1)
                map.remove(topic);
            else
                map.put(topic, map.get(topic) - 1);

        recurs(idx + 1, num);
    }

}