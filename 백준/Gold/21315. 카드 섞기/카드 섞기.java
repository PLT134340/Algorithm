import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> result = new ArrayList<>();
        String[] line = br.readLine().split(" ");

        for (int i = 0; i < n; i++) {
            result.add(Integer.parseInt(line[i]));
        }

        ArrayList<Integer> init = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            init.add(i);
        }

        int k1 = 1;
        for (int i = 2; i < n; i *= 2) {
            ArrayList<Integer> first = mix(init, i);
            int k2 = 1;

            for (int j = 2; j < n; j *= 2) {
                ArrayList<Integer> second = mix(first, j);

                if (second.equals(result)) {
                    System.out.println(k1 + " " + k2);
                    return;
                }

                k2++;
            }

            k1++;
        }

    }

    static ArrayList<Integer> mix(ArrayList<Integer> list, int num) {
        ArrayList<Integer> result = new ArrayList<>();

        if (num == 1) {
            result.add(list.get(list.size() - 1));
            result.addAll(list.subList(0, list.size() - 1));
            return result;
        }

        result.addAll(mix(new ArrayList<>(list.subList(list.size() - num, list.size())), num / 2));
        result.addAll(list.subList(0, list.size() - num));
        return result;
    }
}
