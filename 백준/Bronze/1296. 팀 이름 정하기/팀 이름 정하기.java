import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String name = scanner.next();
        
        int nameCount[] = new int[4];
        for (int j = 0; j < name.length(); j++)
            if (name.charAt(j) == 'L')
                nameCount[0]++;
            else if (name.charAt(j) == 'O')
                nameCount[1]++;
            else if (name.charAt(j) == 'V')
                nameCount[2]++;
            else if (name.charAt(j) == 'E')
                nameCount[3]++;
        
        int n = scanner.nextInt();
        int max = -1;
        String answer = "";
        
        for (int i = 0; i < n; i++) {
            String teamName = scanner.next();
            
            int teamCount[] = nameCount.clone();
            for (int j = 0; j < teamName.length(); j++)
                if (teamName.charAt(j) == 'L')
                    teamCount[0]++;
                else if (teamName.charAt(j) == 'O')
                    teamCount[1]++;
                else if (teamName.charAt(j) == 'V')
                    teamCount[2]++;
                else if (teamName.charAt(j) == 'E')
                    teamCount[3]++;
                
            int score = 1;
            for (int j = 0; j < 3; j++)
                for (int k = j + 1; k < 4; k++)
                    score = (score * (teamCount[j] + teamCount[k])) % 100;
                    
            // System.out.println(String.format("name: %s, score: %d", teamName, score));
                    
            if (max < score) {
                max = score;
                answer = teamName;
            } else if (max == score && answer.compareTo(teamName) > 0)
                 answer = teamName;
        }
        
        System.out.println(answer);
    }
}