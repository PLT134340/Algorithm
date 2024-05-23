import java.util.*;

class Main {

    static final int appleLength = 12;
    static final int appleWeight = 500;
    static final int appleValue = 12000 / 3;
    static final int appleBoxWeight = 1000;
    static final int pearTotalWeight = 120 * 50;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        
        int weight = 0;
        int value = 0;
        
        for (int i = 0; i < n; i++) {
            String t = scanner.next();
            int w = scanner.nextInt();
            int h = scanner.nextInt();
            int l = scanner.nextInt();
            
            if (t.equals("A")) {
                int num = (w / appleLength) * (h / appleLength) * (l / appleLength);
                weight += appleBoxWeight + appleWeight * num;
                value += appleValue * num;
            } else
                weight += pearTotalWeight;
        }
        
        System.out.println(weight);
        System.out.println(value);
    }
}