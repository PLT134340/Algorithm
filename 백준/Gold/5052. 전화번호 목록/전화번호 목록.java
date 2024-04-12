import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            boolean hasConsistency = true;
            String[] numbers = new String[n];
            Set<String> set = new HashSet<>();
            
            for (int j = 0; j < n; j++) {
                numbers[j] = br.readLine();
                set.add(numbers[j]);
            }
            
            for (int j = 0; j < n; j++) {
                if (!hasConsistency)
                    continue;
                
                StringBuilder sb = new StringBuilder();
                
                for (int k = 0; k < numbers[j].length() - 1; k++) {
                    sb.append(numbers[j].charAt(k));
                    if (set.contains(sb.toString())) {
                        hasConsistency = false;
                        break;
                    }
                }
            }
            
            if (hasConsistency)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}