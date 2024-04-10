import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        List<Long> l = Arrays.stream(br.readLine().split(" "))
                .map(s -> Long.parseLong(s))
                .collect(Collectors.toList());

        l.sort(Comparator.naturalOrder());

        int left = 0;
        int right = l.size() - 1;
        
        long min = Math.abs(l.get(left) + l.get(right));
        long[] answer = { l.get(left), l.get(right) };

        while (left < right) {
            long sum = l.get(left) + l.get(right);

            if (min > Math.abs(sum)) {
                min = Math.abs(sum);
                answer[0] = l.get(left);
                answer[1] = l.get(right);
            }

            if (sum > 0)
                right--;
            else if (sum < 0)
                left++;
            else {
                System.out.println(answer[0] + " " + answer[1]);
                return;
            }
        }

        System.out.println(answer[0] + " " + answer[1]);
    }
}