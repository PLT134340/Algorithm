import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        List<String> list = new ArrayList<>();

        for (int i = 0; i < str.length(); i++) {
            list.add(str.substring(i));
        }

        list.sort(Comparator.naturalOrder());

        StringBuilder sb = new StringBuilder();
        for (String elem : list) {
            sb.append(elem).append("\n");
        }

        System.out.print(sb);
    }
}
