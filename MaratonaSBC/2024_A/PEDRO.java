package maratona_2024.prova;

import java.util.Scanner;

public class A_Atencao_a_Reuniao {
    public static Scanner leitor = new Scanner(System.in);

    public static void main(String[] args) {
        while(true) {

            // Lendo a quantidade de funcionários (N) e o tempo total (T)
            System.out.print("\nDigite o número de funcionários: ");
            if (!leitor.hasNextInt()) return;
            int n = leitor.nextInt();

            System.out.print("\nDigite o tempo máximo da reunião: ");
            if (!leitor.hasNextInt()) return;
            int t = leitor.nextInt();

            // 1. Calcular o tempo total gasto com intervalos (2 min entre cada fala)
            // Se houver apenas 1 funcionário, o intervalo é 0.
            int tempoIntervalos = (n - 1) * 2;

            // 2. Calcular quanto tempo sobra para as falas
            int tempoDisponivelParaFalas = t - tempoIntervalos;

            // 3. Validar se o tempo restante permite que cada um fale pelo menos 1 min
            // Também verificamos se o tempo de intervalos não superou o tempo total
            if (tempoDisponivelParaFalas >= n && n > 0) {

                // Calculando o tempo de cada um (divisão inteira)
                int tempoCadaUm = tempoDisponivelParaFalas / n;

                System.out.printf("O tempo de fala de cada funcionário é de %dmin!", tempoCadaUm);

            } else {
                // Caso não haja tempo suficiente para a regra de 1min mínimo
                System.out.println("Erro! O tempo de fala dos funcionários é menor do que 1min");
            }

            continuar();
        }
    }

    public static void continuar() {
        leitor.nextLine(); // limpa o buffer

        System.out.println("\nDeseja continuar e marcar a próxima reunião? (Y/N)");
        String resposta = leitor.nextLine();

        if (resposta.equalsIgnoreCase("Y")) {
            return; // continua o loop normal
        } else if (resposta.equalsIgnoreCase("N")) {
            System.out.println("Programa encerrado");
            System.exit(0); // encerra o programa
        }
    }
}