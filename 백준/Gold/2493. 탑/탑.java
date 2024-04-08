import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;
import java.util.stream.Collectors;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        List<Integer> heights = Arrays.asList(br.readLine().split(" "))
                .stream()
                .map(s -> Integer.parseInt(s))
                .collect(Collectors.toList());

        int[] result = new int[n];
        Deque<Node> dq = new ArrayDeque<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!dq.isEmpty() && heights.get(i) > dq.peekLast().num) {
                Node nd = dq.pollLast();
                result[nd.idx] = i + 1;
            }
            dq.offerLast(new Node(i, heights.get(i)));
        }

        for (int i = 0; i < n; i++)
            bw.write(String.valueOf(result[i]) + " ");
        bw.newLine();
        bw.flush();
        bw.close();
    }
}

class Node {
    public int idx;
    public int num;

    public Node(int idx, int num) {
        this.idx = idx;
        this.num = num;
    }
}
