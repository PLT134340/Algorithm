import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        Pair[] pairs = new Pair[3];
        
        for (int i = 0; i < 3; i++) {
            int c = scanner.nextInt();
            int d = scanner.nextInt();
            
            pairs[i] = new Pair(c, d);
        }
        
        int h = scanner.nextInt();
        int time = -1;
        
        while (h > 0) {
            time++;
            for (Pair p : pairs) {
                if (time % p.cycle == 0) {
                    h -= p.damage;
                }
            }
        }
        
        System.out.println(time);
    }   
    
    static class Pair {
        public int cycle;
        public int damage;
        
        public Pair(int cycle, int damage) {
            this.cycle = cycle;
            this.damage = damage;
        }
    }
}