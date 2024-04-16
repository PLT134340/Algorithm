import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        ArrayList<Integer> positiveNumber = new ArrayList<>();
        ArrayList<Integer> negativeNumber = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int tmp = scanner.nextInt();
            if (tmp > 0)
                positiveNumber.add(tmp);
            else
                negativeNumber.add(tmp);
        }
        positiveNumber.sort(Comparator.reverseOrder());
        negativeNumber.sort(Comparator.naturalOrder());

        long sum = 0;
        for (int i = 0; i < positiveNumber.size(); i += 2)
            if (i == positiveNumber.size() - 1)
                sum += positiveNumber.get(i);
            else if (positiveNumber.get(i) * positiveNumber.get(i + 1) > positiveNumber.get(i) + positiveNumber.get(i + 1))
                sum += positiveNumber.get(i) * positiveNumber.get(i + 1);
            else
                sum += positiveNumber.get(i) + positiveNumber.get(i + 1);
        for (int i = 0; i < negativeNumber.size(); i += 2)
            if (i == negativeNumber.size() - 1)
                sum += negativeNumber.get(i);
            else if (negativeNumber.get(i) * negativeNumber.get(i + 1) > negativeNumber.get(i) + negativeNumber.get(i + 1))
                sum += negativeNumber.get(i) * negativeNumber.get(i + 1);
            else
                sum += negativeNumber.get(i) + negativeNumber.get(i + 1);
        
        System.out.println(sum);
    }
}