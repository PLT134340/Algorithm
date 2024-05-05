import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] colors = new String[4];
        for (int i = 0; i < 4; i++)
            colors[i] = scanner.next();
        
        Set<Pair> set = new TreeSet<>();
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                set.add(new Pair(colors[i], colors[j]));
        
        for (Pair p : set)
            System.out.println(p.body + " " + p.tail);
    }
    
    static void swap(String s1, String s2) {
        String tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    
    static class Pair implements Comparable<Pair> {
        public String body;
        public String tail;
        
        public Pair(String body, String tail) {
            this.body = body;
            this.tail = tail;
        }
        
        @Override
        public int compareTo(Pair p) {
            if (body.compareTo(p.body) == 0)
                return tail.compareTo(p.tail);
            else
                return body.compareTo(p.body);
        }
    }
}