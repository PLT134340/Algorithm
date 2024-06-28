import java.io.*;
import java.util.*;

class Main {
    
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int r = Integer.parseInt(line[0]);
        int c = Integer.parseInt(line[1]);
        char[][] matrix = new char[r][c];
        Set<Pair> set = new HashSet<>();
        
        
        for (int i = 0; i < r; i++) {
            String str = br.readLine();
            for (int j = 0; j < c; j++) {
                matrix[i][j] = str.charAt(j);
                if (str.charAt(j) == 'W')
                    set.add(new Pair(i, j));
            }
        }
        
        boolean canPen = true;
        
        for (Pair p : set)
            for (int i = 0; canPen && i < 4; i++) {
                int newY = p.y + dy[i];
                int newX = p.x + dx[i];
                
                if (newY < 0 || newY >= r || newX < 0 || newX >=c)
                    continue;
                
                if (matrix[newY][newX] == 'S') {
                    canPen = false;
                    break;
                } else if (matrix[newY][newX] == 'W')
                    continue;
                    
                matrix[newY][newX] = 'D';
            }
            
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        if (!canPen) {
            bw.write(String.valueOf(0));
            bw.newLine();
        } else {
            bw.write(String.valueOf(1));
            bw.newLine();
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++)
                    bw.write(matrix[i][j]);
                bw.newLine();
            }
        }
        bw.flush();
        bw.close();
    }  
    
    static class Pair {
        public int y;
        public int x;
        
        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
        
        @Override
        public int hashCode() {
            return Objects.hash(y, x);
        }
        
        @Override
        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (!(o instanceof Pair))
                return false;
                
            Pair p = (Pair)o;
            return y == p.y && x == p.x;
        }
    }
}