package maratona_2023.prova;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class F_Ferias_Cansativas {

    private static BufferedReader reader;
    private static StringTokenizer tokenizer;

    private static String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = reader.readLine();
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private static int nextInt() throws IOException {
        String token = next();
        if (token == null) return 0;
        return Integer.parseInt(token);
    }

    public static void main(String[] args) {
        long startTime = System.nanoTime();

        try {
            File myFile = new File("Java Solutions/input.txt");
            if (myFile.exists()) {
                reader = new BufferedReader(new FileReader(myFile));
            } else {
                reader = new BufferedReader(new InputStreamReader(System.in));
            }

            int D = nextInt();
            int Cn = nextInt();
            int Rn = nextInt();

            int[] C = new int[Cn];
            int[] R = new int[Rn];

            for (int i = 0; i < Cn; i++) {
                C[i] = nextInt();
            }

            for (int i = 0; i < Rn; i++) {
                R[i] = nextInt();
            }

            int contador = 0;
            int cIndex = 0;
            int rIndex = 0;

            while (true) {
                if (cIndex < Cn && C[cIndex] <= D) {
                    D -= C[cIndex];
                    cIndex++;
                    contador++;
                } else if (rIndex < Rn) {
                    D += R[rIndex];
                    rIndex++;
                    contador++;
                } else {
                    break;
                }
            }

            System.out.println(contador);

        } catch (IOException ignored) {
        } finally {
            if (reader != null) {
                try { reader.close(); } catch (IOException ignored) {}
            }
        }

        long endTime = System.nanoTime();
        double duration = (endTime - startTime) / 1_000_000.0;
        System.out.printf("Execution Time: %.2fms%n", duration);
    }
}