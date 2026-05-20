package maratona_2023.prova;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class A_Altura_Minima {
    public static void main(String[] args) {
        long startTime = System.nanoTime();

        try {
            File myFile = new File("Java Solutions/input.txt");
            Scanner reader = new Scanner(myFile);

            int n = reader.nextInt();
            int altura =  reader.nextInt();
            int contador = 0;

            for(int i = 0; i < n; i++){
                int k = reader.nextInt();
                if(k <= altura) contador++;
            }

            System.out.println(contador);

            reader.close();


        } catch (FileNotFoundException e) {
            System.out.println("The file 'input.txt' was not found.");
        }

        long endTime = System.nanoTime();
        // Convertendo nanosegundos para milissegundos
        double duration = (endTime - startTime) / 1_000_000.0;
        System.out.println("Execution Time: " + duration);
    }
}