package maratona_2024.prova;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;

public class F_Fracoes_Continuas {
    public static void main(String[] args) {
        long startTime = System.nanoTime();

        try {
            InputStream input = System.in;
            File f = new File("input.txt");
            if (f.exists()) {
                input = new FileInputStream(f);
            }

            int n = 0;
            int c;
            while ((c = input.read()) != -1) {
                if (c >= '0' && c <= '9') {
                    n = n * 10 + (c - '0');
                } else if (n > 0) break;
            }

            if (n >= 0) {
                long a = 1, b = 1;
                for (int i = 0; i < n; i++) {
                    long temp = a + b;
                    a = b;
                    b = temp;
                }
                System.out.println(a);
            }

            if (input instanceof FileInputStream) input.close();

        } catch (Exception e) {
            // Vazio para não gastar processamento
        }

        long endTime = System.nanoTime();
        // Convertendo nanosegundos para milissegundos
        double duration = (endTime - startTime) / 1_000_000.0;

        System.err.printf("Execution time: %.2fms%n", duration);
    }
}