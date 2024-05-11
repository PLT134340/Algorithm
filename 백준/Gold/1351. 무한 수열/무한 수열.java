import java.util.*;

class Main {
    
    static long p, q;
    static Map<Long, Long> map = new TreeMap<>();;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long n = scanner.nextLong();
        p = scanner.nextLong();
        q = scanner.nextLong();
        
        map.put(0L, 1L);
        
        System.out.println(recurs(n));
    }
    
    static long recurs(long n) {
        if (map.containsKey(n))
            return map.get(n);
            
        long tmp = recurs(n / p) + recurs(n / q);
        map.put(n, tmp);
        return tmp;
    }
    
}