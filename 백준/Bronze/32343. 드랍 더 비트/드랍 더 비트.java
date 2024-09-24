import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static int n;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        ArrayList<Integer> allA = new ArrayList<>();
        ArrayList<Integer> allB = new ArrayList<>();

        recurs(0, 0, a, 0, allA);
        recurs(0, 0, b, 0, allB);

        int max = 0;

//        for (int numA : allA)
//            System.out.println(numA);
//        for (int numB : allB)
//            System.out.println(numB);

        for (int numA : allA)
            for (int numB : allB)
                if (max < (numA ^ numB))
                    max = numA ^ numB;

        System.out.println(max);
    }

    static void recurs(int level, int numOfOne, int end, int num, ArrayList<Integer> result) {
        if (numOfOne > end)
            return;
        if (level == n) {
            if (numOfOne == end)
                result.add(num);
            return;
        }

        recurs(level + 1, numOfOne + 1, end, num * 2 + 1, result);
        recurs(level + 1, numOfOne, end, num * 2, result);
    }
}
