import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int r = Integer.parseInt(line[0]);
        int c = Integer.parseInt(line[1]);
        int n = Integer.parseInt(br.readLine());

        Map<Integer, ArrayList<Pair>> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]);
            int v = Integer.parseInt(line[1]);
            int h = Integer.parseInt(line[2]);

            if (!map.containsKey(a))
                map.put(a, new ArrayList<>());

            map.get(a).add(new Pair(v, h));
        }

        int maxIdx = 100_000;
        long maxArea = 1;

        for (var entry : map.entrySet()) {
            ArrayList<Pair> pairs = entry.getValue();

            long minY = 100_000;
            long maxY = 1;
            long minX = 100_000;
            long maxX = 1;

            for (Pair p : pairs) {
                if (minY > p.y)
                    minY = p.y;
                if (maxY < p.y)
                    maxY = p.y;
                if (minX > p.x)
                    minX = p.x;
                if (maxX < p.x)
                    maxX = p.x;
            }

            long area = (maxY - minY + 1) * (maxX - minX + 1);

//            System.out.println(entry.getKey() + ": " + area);

            if (maxArea < area || (maxArea == area && maxIdx > entry.getKey())) {
                maxIdx = entry.getKey();
                maxArea = area;
            }
        }

        System.out.println(maxIdx + " " + maxArea);
    }

    static class Pair {
        public int y;
        public int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
