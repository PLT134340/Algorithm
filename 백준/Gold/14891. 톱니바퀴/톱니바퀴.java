import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String[] str = new String[4];
        for (int i = 0; i < 4; i++)
            str[i] = scanner.next();
        
        Cogs cogs = new Cogs(str);
        
        int k = scanner.nextInt();
        for (int i = 0; i < k; i++) {
            int num = scanner.nextInt();
            int way = scanner.nextInt();
            cogs.rotate(num - 1, way);
        }
        
        System.out.println(cogs.getScore());
    }   
    
    static class Cogs {
        private Cog[] cogs;
        
        public Cogs(String[] str) {
            cogs = new Cog[4];
            for (int i = 0; i < 4; i++)
                cogs[i] = new Cog(str[i]);
        }
        
        public void rotate(int idx, int way) {
            if (canRotateLeft(idx))
                rotateLeft(idx - 1, -way);
            if (canRotateRight(idx))
                rotateRight(idx + 1, -way);
            cogs[idx].rotate(way);
        }
        
        private boolean canRotateLeft(int idx) {
            if (idx - 1 < 0)
                return false;
            return cogs[idx].getLeft() ^ cogs[idx - 1].getRight();
        }
        
        private boolean canRotateRight(int idx) {
            if (idx + 1 >= 4)
                return false;
            return cogs[idx].getRight() ^ cogs[idx + 1].getLeft();
        }
        
        private void rotateLeft(int idx, int way) {
            if (canRotateLeft(idx))
                rotateLeft(idx - 1, -way);
            cogs[idx].rotate(way);
        }
        
        private void rotateRight(int idx, int way) {
            if (canRotateRight(idx))
                rotateRight(idx + 1, -way);
            cogs[idx].rotate(way);   
        }
        
        public int getScore() {
            int sum = 0;
            int score = 1;
            for (int i = 0; i < 4; i++, score *= 2)
                if (cogs[i].getTop())
                    sum += score;
            return sum;
        }
    }
    
    static class Cog {
        private boolean[] arr;
        private int top;
        
        public Cog(String str) {
            arr = new boolean[8];
            for (int i = 0; i < 8; i++)
                arr[i] = str.charAt(i) != '0';
            top = 0;
        }
        
        public boolean getTop() {
            return arr[top];
        }
        
        public boolean getLeft() {
            int idx = (top + 6) % 8;
            return arr[idx];
        }
        
        public boolean getRight() {
            int idx = (top + 2) % 8;
            return arr[idx];
        }
        
        public void rotate(int way) {
            if (way == -1)
                top++;
            else
                top--;
            top = (top + 8) % 8;
        }
    }
}