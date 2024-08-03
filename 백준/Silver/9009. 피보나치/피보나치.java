import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.TreeSet;

class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int t = Integer.parseInt(br.readLine());
        TreeSet<Integer> set = new TreeSet<>();
        
        set.add(0);
        set.add(1);
        int sum = 1;
        
        while (sum <= 1_000_000_000) {
            int last = set.last();
            set.add(sum);
            sum += last;
        }
        
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            ArrayList<Integer> arr = new ArrayList<>();
            
            while (n > 0) {
                int floor = set.floor(n);
                arr.add(floor);
                n -= floor;
            }
            
            for (int j = arr.size() - 1; j >= 0; j--)
                System.out.print(arr.get(j) + " ");
            System.out.println();
        }
    }
}