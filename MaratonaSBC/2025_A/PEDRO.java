package maratona_2025.prova;

import java.util.Scanner;

public class A_Alimentacao_Saudavel {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        while(true) {

            // INPUT - Número de frutas
            System.out.print("\nDigite o número de frutas: ");
            if (!sc.hasNextInt()) return;
            int n = sc.nextInt();

            // INPUT - Número de turmas
            System.out.print("\nDigite a quantidade de turmas: ");
            if (!sc.hasNextInt()) return;
            int m = sc.nextInt();

            int[][] matrix = new int[n][m];

            // INPUT - Preenchendo os elementos da matriz
            System.out.println("Enter the elements of the matrix:");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = sc.nextInt();
                }
            }

            // Print dos elementos da matriz
            System.out.println("Your Matrix:");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    System.out.print(matrix[i][j] + " ");
                }
                System.out.println();
            }

            // Soma total dos maiores valores de cada coluna
            int sum_output = 0;

            // Loop para pegar o maior valor de cada coluna(turma)
            for (int j = 0; j < m; j++) {
                int max = matrix[0][j];
                for (int i = 1; i < n; i++) {
                    if (matrix[i][j] > max) max = matrix[i][j];
                }
                sum_output += max;
            }

            // OUTPUT - Soma total
            System.out.printf("Output: %d", sum_output);

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