import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] line = br.readLine().toCharArray();
        int robot = 0;
        int box = 0;
        int goal = 0;

        for (int i = 0; i < line.length; i++)
            if (line[i] == '@')
                robot = i;
            else if (line[i] == '#')
                box = i;
            else if (line[i] == '!')
                goal = i;

        if (!((robot < box && box < goal) || (robot > box && box > goal))) {
            System.out.println(-1);
            return;
        }

        System.out.println(Math.abs(goal - robot) - 1);
    }
}