import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");

        ArrayList<Card> cards = new ArrayList<>();
        ArrayList<ArrayList<Card>> sortedBySuit = new ArrayList<>();
        for (int i = 0; i < 4; i++)
            sortedBySuit.add(new ArrayList<>());

        for (int i = 0; i < n; i++) {
            String[] symbols = line[i].split("");

            Rank rank = Rank.findBySymbol(symbols[0]);
            Suit suit = Suit.findBySymbol(symbols[1]);

            Card card = new Card(rank, suit);
            cards.add(card);
            sortedBySuit.get(suit.getIndex()).add(card);
        }
        for (ArrayList<Card> bySuit : sortedBySuit)
            bySuit.sort(Comparator.comparing(c -> c.getRank().getOrder()));

        ArrayList<int[]> permutations = suitPermutation(4);
        ArrayList<boolean[]> orders = rankOrder(4);
        int num = 1;
        int maxLength = 0;

        for (int[] permutation : permutations)
            for (boolean[] order : orders) {
                ArrayList<Card> sortedCards = new ArrayList<>();

                for (int i = 0; i < 4; i++) {
                    ArrayList<Card> bySuit = sortedBySuit.get(permutation[i]);

                    if (order[i])
                        sortedCards.addAll(bySuit);
                    else
                        for (int j = bySuit.size() - 1; j >= 0; j--)
                            sortedCards.add(bySuit.get(j));
                }

                int length = LISLength(sortedCards, cards);
                if (maxLength < length)
                    maxLength = length;

//                System.out.print(num++ + ": ");
//                for (Card card : sortedCards)
//                    System.out.print(card + " ");
//                System.out.println();
            }

        System.out.println(n - maxLength);

//        for (Card card : cards)
//            System.out.printf("%s ", card);
//        System.out.println();
//
//        for (var list : sortedBySuit)
//            for (Card card : list)
//                System.out.printf("%s ", card);
//        System.out.println();
//
//        for (int[] p : permutation) {
//            for (int i = 0; i < 4; i++)
//                System.out.print(p[i] + " ");
//            System.out.println();
//        }

    }

    static int LISLength(ArrayList<Card> sortedCards, ArrayList<Card> cards) {
        int[] lengths = new int[cards.size()];
        int[] idx = new int[cards.size()];

        for (int i = 0; i < cards.size(); i++)
            for (int j = 0; j < sortedCards.size(); j++)
                if (cards.get(i) == sortedCards.get(j))
                    idx[i] = j;

        for (int i = 0; i < cards.size(); i++) {
            int max = 0;
            for (int j = 0; j < i; j++) {
                if (idx[j] < idx[i] && max < lengths[j])
                    max = lengths[j];
            }
            lengths[i] = max + 1;
        }

        int result = lengths[0];
        for (int i = 1; i < lengths.length; i++)
            if (result < lengths[i])
                result = lengths[i];
        return result;
    }

    static ArrayList<int[]> suitPermutation(int size) {
        ArrayList<int[]> result = new ArrayList<>();
        suitPermutationRecurse(0, size, new int[size], new boolean[size], result);
        return result;
    }

    static void suitPermutationRecurse(int level, int endSize, int[] arr, boolean[] isVisited, ArrayList<int[]> result) {
        if (level == endSize) {
            result.add(arr.clone());
            return;
        }

        for (int i = 0; i < endSize; i++) {
            if (isVisited[i])
                continue;

            arr[level] = i;
            isVisited[i] = true;
            suitPermutationRecurse(level + 1, endSize, arr, isVisited, result);
            isVisited[i] = false;
        }
    }

    static ArrayList<boolean[]> rankOrder(int size) {
        ArrayList<boolean[]> result = new ArrayList<>();
        rankOrderRecurse(0, size, new boolean[size], result);
        return result;
    }

    static void rankOrderRecurse(int level, int endSize, boolean[] arr, ArrayList<boolean[]> result) {
        if (level == endSize) {
            result.add(arr.clone());
            return;
        }

        for (int i = 0; i < 2; i++) {
            arr[level] = i == 0;
            rankOrderRecurse(level + 1, endSize, arr, result);
        }
    }

    static class Card {
        private final Rank rank;
        private final Suit suit;

        public Card(Rank rank, Suit suit) {
            this.rank = rank;
            this.suit = suit;
        }

        public Rank getRank() {
            return rank;
        }

        public Suit getSuit() {
            return suit;
        }

        @Override
        public String toString() {
            return rank.getSymbol() + suit.getSymbol();
        }
    }

    enum Suit {
        SPADE("s", 0),
        HEART("h", 1),
        DIAMOND("d", 2),
        CLUB("c", 3);

        private final String symbol;
        private final int index;

        Suit(String symbol, int index) {
            this.symbol = symbol;
            this.index = index;
        }

        public String getSymbol() {
            return symbol;
        }

        public int getIndex() {
            return index;
        }

        static Suit findBySymbol(String symbol) {
            for (Suit suit : values())
                if (suit.symbol.equals(symbol))
                    return suit;
            return null;
        }
    }

    enum Rank {
        TWO("2", 1),
        THREE("3", 2),
        FOUR("4", 3),
        FIVE("5", 4),
        SIX("6", 5),
        SEVEN("7", 6),
        EIGHT("8", 7),
        NINE("9", 8),
        TEN("T", 9),
        JACK("J", 10),
        QUEEN("Q", 11),
        KING("K", 12),
        ACE("A", 13);

        private final String symbol;
        private final int order;

        Rank(String symbol, int order) {
            this.symbol = symbol;
            this.order = order;
        }

        public String getSymbol() {
            return symbol;
        }

        public int getOrder() {
            return order;
        }

        static Rank findBySymbol(String symbol) {
            for (Rank rank : values())
                if (rank.symbol.equals(symbol))
                    return rank;
            return null;
        }
    }
}