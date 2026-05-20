package maratona_2025.prova;

import java.util.Scanner;

public class J_Joao_Joao {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {

            int[] dificuldade = {1, 2, 3, 4};
            int[] input = new int[10];
            int sucess = 0;

            // INPUT
            System.out.print("\nDigite o número de frutas: ");
            if (!sc.hasNextInt()) return;
            for(int i = 0; i < 10; i++){
                input[i] = sc.nextInt();
                if(input[i] == dificuldade[i]){
                    sucess += 1;
                }
            }

            int output = dificuldade.length - sucess;


            // OUTPUT
            System.out.println("Output:");

            continuar();
        }
    }

    public static void continuar() {
        sc.nextLine(); // limpa o buffer

        System.out.println("\nDeseja continuar? (Y/N)");
        String resposta = sc.nextLine();

        if (resposta.equalsIgnoreCase("Y")) {
            return; // continua o loop normal
        } else if (resposta.equalsIgnoreCase("N")) {
            System.out.println("Programa encerrado");
            System.exit(0); // encerra o programa
        }
    }
}
