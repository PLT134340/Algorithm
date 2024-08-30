import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double totalCredit = 0;
        double totalGrade = 0;

        for (int i = 0; i < 20; i++) {
            String className = scanner.next();
            double credit = scanner.nextDouble();
            String grade = scanner.next();
            double score;

            if (grade.equals("P"))
                continue;
            else if (grade.equals("A+"))
                score = 4.5;
            else if (grade.equals("A0"))
                score = 4.0;
            else if (grade.equals("B+"))
                score = 3.5;
            else if (grade.equals("B0"))
                score = 3.0;
            else if (grade.equals("C+"))
                score = 2.5;
            else if (grade.equals("C0"))
                score = 2.0;
            else if (grade.equals("D+"))
                score = 1.5;
            else if (grade.equals("D0"))
                score = 1.0;
            else
                score = 0;

            totalCredit += credit;
            totalGrade += score * credit;
        }

        System.out.println(totalGrade / totalCredit);
    }

}