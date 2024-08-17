import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        ArrayList<Pair> arrayList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int query = scanner.nextInt();
            int first = scanner.nextInt();
            int second = scanner.nextInt();

            if (query == 1) {
                arrayList.add(new Pair(first, second));
            } else {
                first--;
                second--;

                Deque<Integer> dq = new ArrayDeque<>();
                boolean[] isVisited = new boolean[arrayList.size()];

                dq.offerLast(first);
                isVisited[first] = true;
                boolean canMove = false;

                while (!dq.isEmpty()) {
                    int idx = dq.pollFirst();

                    if (idx == second) {
                        canMove = true;
                        break;
                    }

                    Pair now = arrayList.get(idx);

                    for (int j = 0; j < arrayList.size(); j++) {
                        Pair next = arrayList.get(j);
                        if (!isVisited[j]
                                && ((now.start > next.start && now.start < next.end)
                                || (now.end > next.start && now.end < next.end))) {
                            dq.offerLast(j);
                            isVisited[j] = true;
                        }
                    }
                }

                if (canMove)
                    System.out.println(1);
                else
                    System.out.println(0);
            }
        }
    }

    static class Pair {
        public int start;
        public int end;

        public Pair(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}