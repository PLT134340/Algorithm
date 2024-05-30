import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int k = scanner.nextInt();
        
        String[] gist = {
            "G...",
            ".I.T",
            "..S."
        };
        
        StringBuilder result = new StringBuilder();
        
        for (int i = 0; i < 3; i++) {
            StringBuilder line = new StringBuilder();
            
            for (int j = 0; j < 4; j++)
                for (int l = 0; l < k; l++)
                    line.append(gist[i].charAt(j));
            line.append('\n');
            
            for (int j = 0; j < k; j++)
                result.append(line);
        }
        
        System.out.print(result);
    }   
}