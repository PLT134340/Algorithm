import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<String> words = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String input = br.readLine();
            boolean willAdd = true;

            for (int j = 0; j < words.size(); j++) {
                if (words.get(j).startsWith(input)) {
                    willAdd = false;
                    break;
                }
                if (input.startsWith(words.get(j))) {
                    willAdd = false;
                    words.set(j, input);
                    break;
                }
            }

            if (willAdd)
                words.add(input);
        }

        System.out.println(words.size());
    }
}