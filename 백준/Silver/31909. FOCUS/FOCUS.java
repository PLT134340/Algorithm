import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        
        int[] pos = new int[8];
        for (int i = 0; i < 8; i++)
            pos[i] = i;
        
        for (int i = 0; i < n; i++) {
            int inst = scanner.nextInt();
            
            ArrayList<Integer> list = new ArrayList<>();
            int digit = 0;
            while (inst > 0) {
                if (inst % 2 == 1)
                    list.add(digit);
                inst /= 2;
                digit++;
            }
            
            if (list.size() != 2)
                continue;
            
            // System.out.println(list.get(0) + " " + list.get(1));
                
            int tmp = pos[list.get(0)];
            pos[list.get(0)] = pos[list.get(1)];
            pos[list.get(1)] = tmp;
        }
        
        int k = scanner.nextInt();
        // for (int i = 0; i < 8; i++)
        //     System.out.println(pos[i]);
        System.out.println(pos[k]);
    }   
}