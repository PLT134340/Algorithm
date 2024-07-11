import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        int q = Integer.parseInt(line[2]);
        
        CompetitionManager cm = new CompetitionManager(n, m);
        
        for (int i = 0; i < q; i++) {
            line = br.readLine().split(" ");
            int takenTime = Integer.parseInt(line[0]);
            int teamNum = Integer.parseInt(line[1]);
            int problemNum = Integer.parseInt(line[2]);
            String result = line[3];
            
            cm.grade(takenTime, teamNum, problemNum, result);
        }
        
        cm.sortScore();
        cm.printRank();
    }

    static class CompetitionManager {
        ArrayList<Team> teams;

        public CompetitionManager(int teamCount, int problemCount) {
            teams = new ArrayList<>();
            for (int i = 0; i < teamCount; i++)
                teams.add(new Team(i + 1, problemCount));
        }

        public void grade(int takenTime, int teamNum, int problemNum, String result) {
            if (result.equals("AC"))
                teams.get(teamNum - 1).accept(problemNum, takenTime);
            else
                teams.get(teamNum - 1).wrong(problemNum);
        }

        public void sortScore() {
            teams.sort(Comparator.comparing(Team::getSolvedCount, Comparator.reverseOrder())
                    .thenComparing(Team::getTotalTime)
                    .thenComparing(Team::getTeamNum));
        }
        
        public void printRank() {
            for (Team team : teams)
                System.out.println(team.getTeamNum() + " " + team.getSolvedCount() + " " + team.getTotalTime());
        }
    }

    static class Team {
        int teamNum;
        int solvedCount;
        int[] wrongCount;
        boolean[] isAccepted;
        int totalTime;

        public Team(int teamNum, int problemCount) {
            this.teamNum = teamNum;
            this.solvedCount = 0;
            this.wrongCount = new int[problemCount];
            this.isAccepted = new boolean[problemCount];
            this.totalTime = 0;
        }
        
        public int getTeamNum() {
            return teamNum;
        }

        public int getSolvedCount() {
            return solvedCount;
        }

        public int getTotalTime() {
            return totalTime;
        }

        public void wrong(int problemNum) {
            wrongCount[problemNum - 1]++;
        }

        public void accept(int problemNum, int takenTime) {
            if (isAccepted[problemNum - 1])
                return;
            
            solvedCount++;
            isAccepted[problemNum - 1] = true;
            totalTime += takenTime + wrongCount[problemNum - 1] * 20;
        }
    }
}