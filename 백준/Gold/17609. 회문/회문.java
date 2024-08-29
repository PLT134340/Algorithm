import java.util.Scanner;

class Main {

    static char[] str;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t; i++) {
            str = scanner.next().toCharArray();
            int result = recurs(0, str.length - 1, 0);
            sb.append(result).append("\n");
        }

        System.out.print(sb);
    }

    static int recurs(int left, int right, int result) {
        if (left >= right)
            return result;
        else if (result == 2)
            return result;

        if (str[left] == str[right])
            return recurs(left + 1, right - 1, result);
        else
            return Math.min(
                    recurs(left + 1, right, result + 1),
                    recurs(left, right - 1, result + 1));
    }
    
}