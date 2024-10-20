import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        Map<String, ArrayList<String>> edges = getEdges(begin, words);
        Deque<Pair> deque = new ArrayDeque<>();
        Set<String> isVisited = new HashSet<>();
        
        deque.offerLast(new Pair(0, begin));
        isVisited.add(begin);
        
        while (!deque.isEmpty()) {
            Pair pair = deque.pollFirst();
            
            if (pair.word.equals(target))
                return pair.length;

            
            for (String next : edges.get(pair.word)) {
                if (isVisited.contains(next))
                    continue;
                
                deque.offerLast(new Pair(pair.length + 1, next));
                isVisited.add(next);
            }
        }
        
        return 0;
    }
    
    private Map<String, ArrayList<String>> getEdges(String begin, String[] words) {
        Map<String, ArrayList<String>> edges = new HashMap<>();
        
        for (String key : words)
            edges.put(key, new ArrayList<>());
        edges.put(begin, new ArrayList<>());
        
        for (var entry : edges.entrySet()) {
            String key = entry.getKey();
            for (String word : words) {
                int diffCount = 0;
                for (int i = 0; i < word.length(); i++)
                    if (key.charAt(i) != word.charAt(i))
                        diffCount++;
                
                if (diffCount != 1)
                    continue;
                
                edges.get(key).add(word);
            }
        }
        
        return edges;
    }
    
    static class Pair {
        public int length;
        public String word;
        
        public Pair(int length, String word) {
            this.length = length;
            this.word = word;
        }
    }
}