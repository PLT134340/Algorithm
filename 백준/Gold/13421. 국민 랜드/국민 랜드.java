import java.util.*;

class Main {

    static Pair[] pairs = new Pair[4];
    static long min = Long.MAX_VALUE;
    static int[] mapping = new int[4];
    static Set<Integer> set = new HashSet<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 4; i++) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();

            pairs[i] = new Pair(x * 2, y * 2);
        }

        long left = 1;
        long leftValue = recurs(0, left);

        long right = 1_000_000_000_000L;
        long rightValue = recurs(0, right);

        while (left + 3 < right) {
            long mid1 = (2 * left + right) / 3;
            long mid1Value = recurs(0, mid1);

            long mid2 = (left + 2 * right) / 3;
            long mid2Value = recurs(0, mid2);

//            System.out.printf("%d %d %d %d\n", left, mid1, mid2, right);
//            System.out.printf("%d %d %d %d\n", leftValue, mid1Value, mid2Value, rightValue);

            if (mid1Value >= mid2Value) {
                left = mid1;
                leftValue = mid1Value;
            } else {
                right = mid2;
                rightValue = mid2Value;
            }
        }

        long result = left;
        long minValue = recurs(0, result);

        for (long i = left; i <= right; i++) {
            long tmp = recurs(0, i);
            if (minValue >= tmp) {
                result = i;
                minValue = tmp;
            }
//            System.out.printf("%d: %d\n", i, tmp);
        }

        System.out.println(result);
    }

    static long manhattanDistance(long length) {
        Pair[] square = {
                new Pair(length, length),
                new Pair(-length, length),
                new Pair(-length, -length),
                new Pair(length, -length)
        };

        long result = 0;
        for (int i = 0; i < 4; i++)
            result += Math.abs(square[mapping[i]].x - pairs[i].x) + Math.abs(square[mapping[i]].y - pairs[i].y);

        return result;
    }

    static long recurs(int lv, long length) {
        if (lv == 0)
            min = Long.MAX_VALUE;
        else if (lv == 4) {
            long distance = manhattanDistance(length);
            if (min > distance)
                min = distance;
            return min;
        }

        for (int i = 0; i < 4; i++) {
            if (set.contains(i))
                continue;

            mapping[lv] = i;
            set.add(i);
            recurs(lv + 1, length);
            set.remove(i);
        }

        return min;
    }

    static class Pair {
        public long x;
        public long y;

        public Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

}