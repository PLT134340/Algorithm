import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int h = scanner.nextInt();

        if (a == b) {
            System.out.println(-1);
            return;
        } else if (a > b) {
            int tmp = b;
            b = a;
            a = tmp;
        }

        double x = (double) (a * h) / (b - a);
        double inRadiusSquare = x * x + a * a;
        double outRadiusSquare = (x + h) * (x + h) + b * b;

        System.out.println((outRadiusSquare - inRadiusSquare) * Math.PI);
    }
}