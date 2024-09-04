import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int m = Integer.parseInt(br.readLine());
        Map<String, Integer> map = new HashMap<>();

        for (int i = 0; i < m; i++) {
            String[] line = br.readLine().split(" ");
            String name = line[0];
            int amount = Integer.parseInt(line[1]);

            if (!map.containsKey(name))
                map.put(name, amount);
            else
                map.put(name, map.get(name) + amount);
        }

        ArrayList<Integer> amounts = new ArrayList<>(map.values());

        for (int i = 0; i < amounts.size(); i++)
            for (int j = 0; j < amounts.size(); j++)
                if (i == j)
                    continue;
                else if (Math.floor(amounts.get(i) * 1.618) == amounts.get(j)) {
                    System.out.println("Delicious!");
                    return;
                }
        System.out.println("Not Delicious...");
    }
}