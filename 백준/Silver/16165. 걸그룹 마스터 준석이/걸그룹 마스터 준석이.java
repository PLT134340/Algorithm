import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        Map<String, ArrayList<String>> findMember = new HashMap<>();
        Map<String, String> findTeam = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String teamName = br.readLine();
            int memberCount = Integer.parseInt(br.readLine());
            ArrayList<String> members = new ArrayList<>();

            for (int j = 0; j < memberCount; j++) {
                String memberName = br.readLine();

                members.add(memberName);
                findTeam.put(memberName, teamName);
            }

            members.sort(Comparator.naturalOrder());
            findMember.put(teamName, members);
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < m; i++) {
            String question = br.readLine();
            int type = Integer.parseInt(br.readLine());

            if (type == 1)
                sb.append(findTeam.get(question)).append("\n");
            else
                for (String member : findMember.get(question))
                    sb.append(member).append("\n");
        }

        System.out.print(sb);
    }
}