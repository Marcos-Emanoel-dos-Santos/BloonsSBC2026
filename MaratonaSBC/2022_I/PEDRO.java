package maratona_2022.prova;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class I_Interceptando_Informacoes {
    public static void main(String[] args) {
        long startTime = System.nanoTime();

        try {
            File myFile = new File("Java Solutions/input.txt");
            Scanner reader = new Scanner(myFile);

            // Começamos assumindo que a sequência é válida
            boolean sucesso = true;

            for (int i = 0; i < 8; i++) {
                try {
                    if (reader.hasNextInt()) {
                        int byte_seq = reader.nextInt();
                        if (byte_seq != 0 && byte_seq != 1) {
                            sucesso = false;
                            break;
                        }
                    } else {
                        sucesso = false;
                        break;
                    }
                } catch (Exception e) {
                    sucesso = false;
                    break;
                }
            }

            if (sucesso) {
                System.out.println('S');
            } else {
                System.out.println('F');
            }

            reader.close();

        } catch (FileNotFoundException e) {
            System.out.println("The file 'input.txt' was not found.");
        }

        long endTime = System.nanoTime();
        double duration = (endTime - startTime) / 1_000_000.0;
        System.out.printf("Execution Time: %.2fms%n", duration);
    }
}