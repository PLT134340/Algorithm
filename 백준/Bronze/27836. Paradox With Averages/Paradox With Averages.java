import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            br.readLine();

            String[] line = br.readLine().split(" ");
            int csNum = Integer.parseInt(line[0]);
            int eNum = Integer.parseInt(line[1]);

            int[] csIQ = new int[csNum];
            int[] eIQ = new int[eNum];

            line = br.readLine().split(" ");
            long csIQSum = 0;
            for (int j = 0; j < csNum; j++) {
                csIQ[j] = Integer.parseInt(line[j]);
                csIQSum += csIQ[j];
            }

            line = br.readLine().split(" ");
            long eIQSum = 0;
            for (int j = 0; j < eNum; j++) {
                eIQ[j] = Integer.parseInt(line[j]);
                eIQSum += eIQ[j];
            }

            long csAverage = csIQSum / csNum;
            long csRemainder = csIQSum % csNum;
            long eAverage = eIQSum / eNum;
            long eRemainder = eIQSum % eNum;

            int result = 0;
            for (int iq : csIQ)
                if ((iq < csAverage || iq == csAverage && csRemainder > 0)
                        && iq > eAverage)
                    result++;

            System.out.println(result);
        }
    }
}