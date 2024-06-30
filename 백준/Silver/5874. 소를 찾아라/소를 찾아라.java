import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String str = scanner.next();
        ArrayList<Integer> arrayList = new ArrayList<>();
        Deque<Character> dq = new ArrayDeque<>();
        
        for (int i = 0; i < str.length(); i++)
            if (dq.isEmpty() || dq.peekLast() == str.charAt(i))
                dq.offerLast(str.charAt(i));
            else {
                arrayList.add(dq.size() - 1);
                dq.clear();
                dq.offerLast(str.charAt(i));
            }
        arrayList.add(dq.size() - 1);
        
        // for (int i = 0; i < arrayList.size(); i++)
        //     System.out.print(arrayList.get(i) + " ");
        // System.out.println();
        
        int result = 0;
        if (str.charAt(0) == ')') {
            if (arrayList.size() % 2 == 1)
                for (int i = arrayList.size() - 3; i >= 0; i -= 2)
                    arrayList.set(i, arrayList.get(i) + arrayList.get(i + 2));
            else
                for (int i = arrayList.size() - 4; i >= 0; i -= 2)
                    arrayList.set(i, arrayList.get(i) + arrayList.get(i + 2));
                    
            for (int i = 1; i + 1 < arrayList.size(); i += 2)
                result += arrayList.get(i) * arrayList.get(i + 1);
        } else {
            if (arrayList.size() % 2 == 1)
                for (int i = arrayList.size() - 4; i >= 0; i -= 2)
                    arrayList.set(i, arrayList.get(i) + arrayList.get(i + 2));
            else
                for (int i = arrayList.size() - 3; i >= 0; i -= 2)
                    arrayList.set(i, arrayList.get(i) + arrayList.get(i + 2));
            
            for (int i = 0; i + 1 < arrayList.size(); i += 2)
                result += arrayList.get(i) * arrayList.get(i + 1);
        }
        
        // for (int i = 0; i < arrayList.size(); i++)
        //     System.out.print(arrayList.get(i) + " ");
        // System.out.println();
        System.out.println(result);
    }
}