import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String str = scanner.next();

        StringBuilder max = new StringBuilder();
        StringBuilder min = new StringBuilder();
        int mCount = 0;

        for (int i = 0; i < str.length(); i++)
            if (str.charAt(i) == 'M')
                mCount++;
            else {
                max.append("5");
                max.append("0".repeat(Math.max(mCount, 0)));

                if (mCount > 0)
                    min.append("1");
                min.append("0".repeat(Math.max(mCount - 1, 0)));
                min.append("5");

                mCount = 0;
            }

        max.append("1".repeat(mCount));
        if (mCount > 0)
            min.append("1");
        min.append("0".repeat(Math.max(mCount - 1, 0)));

        System.out.println(max);
        System.out.println(min);
    }
}