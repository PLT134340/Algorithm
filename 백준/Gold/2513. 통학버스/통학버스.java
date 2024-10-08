import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        int s = Integer.parseInt(line[2]);

        ArrayList<Pair> left = new ArrayList<>();
        ArrayList<Pair> right = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            line = br.readLine().split(" ");
            int position = Integer.parseInt(line[0]);
            int studentCount = Integer.parseInt(line[1]);

            Pair pair = new Pair(position, studentCount);

            if (position < s)
                left.add(pair);
            else
                right.add(pair);
        }

        left.sort(Comparator.comparing(Pair::getPosition));
        right.sort(Comparator.comparing(Pair::getPosition, Comparator.reverseOrder()));

        int totalLength = getTotalLength(left, k, s) + getTotalLength(right, k, s);
        System.out.println(totalLength);
    }

    private static int getTotalLength(ArrayList<Pair> pairs, int k, int s) {
        int totalLength = 0;
        int extra = 0;

        for (Pair pair : pairs) {
            if (extra > pair.studentCount) {
                extra -= pair.studentCount;
                continue;
            }

            int sub = pair.studentCount - extra;
            int moveCount = sub / k;
            extra = k - sub % k;

            if (extra == k)
                extra = 0;
            else
                moveCount++;

            totalLength += moveCount * Math.abs(pair.position - s) * 2;
        }
        return totalLength;
    }

    static class Pair {
        private int position;
        private int studentCount;

        public Pair(int position, int studentCount) {
            this.position = position;
            this.studentCount = studentCount;
        }

        public int getPosition() {
            return position;
        }

        public int getStudentCount() {
            return studentCount;
        }
    }
}
