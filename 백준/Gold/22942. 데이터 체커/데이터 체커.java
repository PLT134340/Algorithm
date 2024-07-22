import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Deque;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Node> arrayList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            int x = Integer.parseInt(line[0]);
            int r = Integer.parseInt(line[1]);

            arrayList.add(new Node(x - r, i, false));
            arrayList.add(new Node(x + r, i, true));
        }

        arrayList.sort(Comparator.comparing(Node::getPos)
                .thenComparing(Node::isRight));
                
        // for (Node nd : arrayList)
        //     System.out.println(String.format("pos: %d, order: %d, isRight: %b", nd.getPos(), nd.getOrder(), nd.isRight()));
        
        Deque<Node> dq = new ArrayDeque<>();
        boolean isSatisfied = true;
        
        for (Node nd : arrayList)
            if (!nd.isRight())
                dq.offerLast(nd);
            else if (dq.isEmpty() || dq.peekLast().getOrder() != nd.getOrder()) {
                isSatisfied = false;
                break;
            } else
                dq.pollLast();
                
        if (isSatisfied && dq.isEmpty())
            System.out.println("YES");
        else
            System.out.println("NO");
    }

    static class Node {
        int pos;
        int order;
        boolean isRight;

        public Node(int pos, int order, boolean isRight) {
            this.pos = pos;
            this.order = order;
            this.isRight = isRight;
        }

        public int getPos() {
            return pos;
        }
        
        public int getOrder() {
            return order;
        }

        public boolean isRight() {
            return isRight;
        }
    }
}