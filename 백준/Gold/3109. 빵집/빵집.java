import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    
    static int r;
    static int c;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        r = Integer.parseInt(line[0]);
        c = Integer.parseInt(line[1]);
        
        boolean[][] matrix = new boolean[r][c];
        for (int i = 0; i < r; i++) {
            line = br.readLine().split("");
            for (int j = 0; j < c; j++)
                if (line[j].equals("."))
                    matrix[i][j] = false;
                else
                    matrix[i][j] = true;
        }
        
        int result = 0;
        for (int i = 0; i < r; i++)
            if (recurs(i, 0, matrix))
                result++;
        
        System.out.println(result);
    }   
    
    static boolean recurs(int y, int x, boolean[][] matrix) {
        if (matrix[y][x])  
            return false;
        matrix[y][x] = true;
        
        if (x == c - 1)
            return true;
        
        if (y - 1 >= 0 && recurs(y - 1, x + 1, matrix))
            return true;
        if (recurs(y, x + 1, matrix))
            return true;
        if (y + 1 < r && recurs(y + 1, x + 1, matrix))
            return true;
            
        return false;
    }
}