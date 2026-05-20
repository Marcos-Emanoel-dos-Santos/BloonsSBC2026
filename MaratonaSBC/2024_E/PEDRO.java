package maratona_2024.prova;

import java.util.Scanner;

public class E_Estojo_de_Joias {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        while(true) {

            // INPUT - Número de colunas e linhas
            System.out.print("\nDigite o número N de colunas e linhas: ");
            if (!sc.hasNextInt()) return;
            int n = sc.nextInt();

            int[][] matrix = new int[n][n];

            // INPUT - Preenchendo os elementos da matriz
            System.out.print("Enter the elements of the matrix:");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = sc.nextInt();
                }
            }   

            // Print dos elementos da matriz
            System.out.println("Your Matrix:");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(matrix[i][j] + " ");
                }
                System.out.println();
            }

            int[] numbers = {matrix[0][n-1], matrix[n-1][n-1], matrix[n-1][0], matrix[0][0]};
            int min = java.util.Arrays.stream(numbers).min().getAsInt();
            int num_giros;

            if(min == matrix[0][n-1]) {
                num_giros = 1;
            } else if(min == matrix[n-1][n-1]) {
                num_giros = 2;
            } else if(min == matrix[n-1][0]) {
                num_giros = 3;
            } else {
                num_giros = 0;
            }

            System.out.printf("Número de giros da caixa: %d", num_giros);

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