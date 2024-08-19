import java.util.List;
import java.util.Scanner;

class Main {

    static char[] word;
    static List<Character> vowel = List.of('A', 'E', 'I', 'O', 'U');
    static long result = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        word = scanner.next().toCharArray();
        boolean hasL = false;

        for (char c : word)
            if (c == 'L') {
                hasL = true;
                break;
            }

        recurs(1, 0, 0, 0, hasL);
        
        System.out.println(result);
    }

    static void recurs(long mul, int idx, int vowelCount, int consonantCount, boolean hasL) {
//        System.out.printf("%d %d %d %d %b\n", mul, idx, vowelCount, consonantCount, hasL);
        if (vowelCount >= 3 || consonantCount >= 3)
            return;

        if (idx == word.length) {
            if (!hasL)
                return;

            result += mul;
            return;
        }

        if (word[idx] == '_') {
            recurs(mul, idx + 1, 0, consonantCount + 1, true);
            recurs(mul * 5, idx + 1, vowelCount + 1, 0, hasL);
            recurs(mul * 20, idx + 1, 0, consonantCount + 1, hasL);
        } else if (vowel.contains(word[idx]))
            recurs(mul, idx + 1, vowelCount + 1, 0, hasL);
        else
            recurs(mul, idx + 1, 0, consonantCount + 1, hasL);
    }

}