import java.util.*;

class Main {
    public static void main(String[] args) {        
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int count = 0;
        Deque<Character> dq = new ArrayDeque<>();
        
        for (int i = 0; i < n; i++) {
            String word = scanner.next();
            for (int j = 0; j < word.length(); j++)
                if (dq.isEmpty())
                    dq.offerLast(word.charAt(j));
                else if (dq.peekLast() != word.charAt(j))
                    dq.offerLast(word.charAt(j));
                else
                    dq.pollLast();
                    
            if (dq.isEmpty())
                count++;
            dq.clear();
        }
        
        System.out.println(count);
    }   
}