package maratona_2023.prova;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class L_Lexicograficamente_Agradavel {
    public static void main(String[] args) {
        long startTime = System.nanoTime();

        try {
            File myFile = new File("Java Solutions/input.txt");
            Scanner reader = new Scanner(myFile);

            String str = reader.nextLine();
            int n = reader.nextInt();

            reader.close();

            int limit = str.length() - n;
            char[] strChar = str.toCharArray();
            int contador;

            do {
                contador = 0;
                for (int i = 0; i < limit; i++) {
                    if(strChar[i] > strChar[i+n]) {
                        char temp = strChar[i];
                        strChar[i] = strChar[i + n];
                        strChar[i + n] = temp;
                        contador++;
                    }
                }
            } while (contador > 0);

            str = new String(strChar);
            System.out.println(str);

        } catch (FileNotFoundException e) {
            System.out.println("The file 'input.txt' was not found.");
        }



        long endTime = System.nanoTime();
        // Convertendo nanosegundos para milissegundos
        double duration = (endTime - startTime) / 1_000_000.0;
        System.out.println("Execution Time: " + duration);
    }
}