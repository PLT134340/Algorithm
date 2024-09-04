import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String encryptedCode = "";
        StringBuilder answer = new StringBuilder();

        while ((encryptedCode = br.readLine()) != null) {
            int[] length = new int[encryptedCode.length()];
            StringBuilder middleText = new StringBuilder();

            for (int i = 0; i < encryptedCode.length(); i++) {
                Moss moss = Moss.findByCharacter(encryptedCode.charAt(i));

                if (moss == null)
                    throw new RuntimeException();

                length[i] = moss.getCode().length();
                middleText.append(moss.getCode());
            }

            int prevIdx = 0;

            for (int i = length.length - 1; i >= 0; i--) {
                String decryptedCode = middleText.substring(prevIdx, prevIdx + length[i]);
                Moss moss = Moss.findByCode(decryptedCode);

                if (moss == null)
                    throw new RuntimeException();

                answer.append(moss.character);
                prevIdx += length[i];
            }

            answer.append("\n");
        }

        System.out.print(answer);
    }

    public enum Moss {
        A('A', ".-"),
        B('B', "-..."),
        C('C', "-.-."),
        D('D', "-.."),
        E('E', "."),
        F('F', "..-."),
        G('G', "--."),
        H('H', "...."),
        I('I', ".."),
        J('J', ".---"),
        K('K', "-.-"),
        L('L', ".-.."),
        M('M', "--"),
        N('N', "-."),
        O('O', "---"),
        P('P', ".--."),
        Q('Q', "--.-"),
        R('R', ".-."),
        S('S', "..."),
        T('T', "-"),
        U('U', "..-"),
        V('V', "...-"),
        W('W', ".--"),
        X('X', "-..-"),
        Y('Y', "-.--"),
        Z('Z', "--.."),
        UNDERSCORE('_', "..--"),
        COMMA(',', ".-.-"),
        PERIOD('.', "---."),
        QUESTIONMARK('?', "----");

        private final char character;
        private final String code;

        Moss(char character, String code) {
            this.character = character;
            this.code = code;
        }

        public static Moss findByCharacter(char character) {
            for (Moss moss : values())
                if (moss.character == character)
                    return moss;
            return null;
        }

        public static Moss findByCode(String code) {
            for (Moss moss : values())
                if (moss.code.equals(code))
                    return moss;
            return null;
        }

        public char getCharacter() {
            return character;
        }

        public String getCode() {
            return code;
        }
    }
}