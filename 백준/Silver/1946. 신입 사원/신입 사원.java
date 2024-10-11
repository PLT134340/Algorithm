import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());

            Applicant[] byDocument = new Applicant[n];

            for (int j = 0; j < n; j++) {
                String[] line = br.readLine().split(" ");
                int document = Integer.parseInt(line[0]);
                int interview = Integer.parseInt(line[1]);

                Applicant applicant = new Applicant(document, interview);
                byDocument[j] = applicant;
            }

            Arrays.sort(byDocument, Comparator.comparing(Applicant::getDocument));
            int minInterview = n;
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (minInterview >= byDocument[j].interview) {
                    minInterview = byDocument[j].interview;
                    count++;
                }
            }

            sb.append(count).append("\n");
        }

        System.out.print(sb);
    }

    static class Applicant {
        private int document;
        private int interview;

        public Applicant(int document, int interview) {
            this.document = document;
            this.interview = interview;
        }

        public int getDocument() {
            return document;
        }

        public int getInterview() {
            return interview;
        }
    }
}
