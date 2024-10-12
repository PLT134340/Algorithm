import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        ArrayList<Integer>[] children = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            children[i] = new ArrayList<>();
        }

        String[] line = br.readLine().split(" ");
        boolean[] isLeaf = new boolean[n];
        Arrays.fill(isLeaf, true);
        int[] parents = new int[n];

        for (int i = 0; i < n; i++) {
            parents[i] = Integer.parseInt(line[i]);

            if (parents[i] == -1)
                continue;

            isLeaf[parents[i]] = false;
            children[parents[i]].add(i);
        }

        int removedNode = Integer.parseInt(br.readLine());
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (isLeaf[i])
                count++;
        }

        Deque<Integer> deque = new ArrayDeque<>();
        deque.offerLast(removedNode);

        while (!deque.isEmpty()) {
            int parent = deque.pollLast();

            if (children[parent].isEmpty()) {
                count--;
                continue;
            }

            for (int child : children[parent]) {
                deque.offerLast(child);
            }
        }

        if (parents[removedNode] != -1 && children[parents[removedNode]].size() == 1)
            count++;

        System.out.println(count);
    }
}
