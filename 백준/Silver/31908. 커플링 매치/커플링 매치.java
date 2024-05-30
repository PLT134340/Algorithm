import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        Map<String, ArrayList<String>> map = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            String ring = scanner.next();
            
            if (ring.equals("-"))
                continue;
            
            if (!map.containsKey(ring))
                map.put(ring, new ArrayList<>());
                
            map.get(ring).add(name);
        }
        
        int count = 0;
        StringBuilder sb = new StringBuilder();
        
        for (ArrayList<String> arrayList : map.values())
            if (arrayList.size() == 2) {
                count++;
                for (int i = 0; i < 2; i++)
                    sb.append(arrayList.get(i) + " ");
                sb.append("\n");
            }
        
        System.out.println(count);
        System.out.print(sb);
    }   
}