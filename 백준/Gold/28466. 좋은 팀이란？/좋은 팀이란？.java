import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] heavenlyStems = new int[10][10];
        int[][] earthlyBranches = new int[12][12];

        for (int i = 0; i < 10; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < 10; j++)
                heavenlyStems[i][j] = Integer.parseInt(line[j]);
        }

        for (int i = 0; i < 12; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < 12; j++)
                earthlyBranches[i][j] = Integer.parseInt(line[j]);
        }

        Set<String> set = new HashSet<>();
        Map<String, ArrayList<Integer>> map = new HashMap<>();

        int hs = 0;
        char eb = 'A';

        for (int i = 0; i < 60; i++) {
            map.put(hs + Character.toString(eb), new ArrayList<>());

            hs++;
            eb++;

            if (hs == 10)
                hs = 0;
            if (eb == 'M')
                eb = 'A';
        }

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            int x = Integer.parseInt(line[0]);

            set.add(line[1]);
            ArrayList<Integer> arrayList = map.get(line[1]);
            arrayList.add(x);
        }
        
        for (String key : set)
            map.get(key).sort(Comparator.reverseOrder());

        // for (var entry : map.entrySet())
        //     if (entry.getValue().size() != 0) {
        //         System.out.print(entry.getKey() + ": ");

        //         for (int val : entry.getValue())
        //             System.out.print(val + " ");
        //         System.out.println();
        //     }

        ArrayList<Integer> result = new ArrayList<>();

        for (String key : set) {
            var arr = map.get(key);

            if (arr.size() < 3)
                continue;

            int hsIdx = key.charAt(0) - '0';
            int ebIdx = key.charAt(1) - 'A';

            int sum = heavenlyStems[hsIdx][hsIdx] * 3 + earthlyBranches[ebIdx][ebIdx] * 3;

            for (int i = 0; i < 3; i++)
                sum += arr.get(i);

            result.add(sum);
        }

        for (String key1 : set)
            for (String key2 : set) {
                if (key1.equals(key2))
                    continue;

                var arr1 = map.get(key1);
                var arr2 = map.get(key2);

                if (!(arr1.size() >= 2 && arr2.size() >= 1))
                    continue;

                int hsIdx1 = key1.charAt(0) - '0';
                int ebIdx1 = key1.charAt(1) - 'A';
                int hsIdx2 = key2.charAt(0) - '0';
                int ebIdx2 = key2.charAt(1) - 'A';

                int sum = heavenlyStems[hsIdx1][hsIdx1] + earthlyBranches[ebIdx1][ebIdx1] +
                        heavenlyStems[hsIdx1][hsIdx2] * 2 + earthlyBranches[ebIdx1][ebIdx2] * 2;

                for (int i = 0; i < 2; i++)
                    sum += arr1.get(i);
                sum += arr2.get(0);

                result.add(sum);
            }

        for (String key1 : set)
            for (String key2 : set)
                for (String key3 : set) {
                    if (key1.equals(key2) || key1.equals(key3) || key2.equals(key3))
                        continue;

                    var arr1 = map.get(key1);
                    var arr2 = map.get(key2);
                    var arr3 = map.get(key3);

                    if (!(arr1.size() >= 1 && arr2.size() >= 1 && arr3.size() >= 1))
                        continue;

                    int hsIdx1 = key1.charAt(0) - '0';
                    int ebIdx1 = key1.charAt(1) - 'A';
                    int hsIdx2 = key2.charAt(0) - '0';
                    int ebIdx2 = key2.charAt(1) - 'A';
                    int hsIdx3 = key3.charAt(0) - '0';
                    int ebIdx3 = key3.charAt(1) - 'A';

                    int sum = heavenlyStems[hsIdx1][hsIdx2] + earthlyBranches[ebIdx1][ebIdx2] +
                            heavenlyStems[hsIdx1][hsIdx3] + earthlyBranches[ebIdx1][ebIdx3] +
                            heavenlyStems[hsIdx2][hsIdx3] + earthlyBranches[ebIdx2][ebIdx3];

                    sum += arr1.get(0);
                    sum += arr2.get(0);
                    sum += arr3.get(0);

                    result.add(sum);
                }

        result.sort(Comparator.reverseOrder());
        System.out.println(result.get(0));
    }
}