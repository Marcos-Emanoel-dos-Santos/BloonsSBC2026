package template;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Template {

    private static BufferedReader reader;
    private static StringTokenizer tokenizer;

    // 1. LEITOR BASE: Caça o próximo pedaço de texto válido (pula espaços e linhas vazias)
    private static String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = reader.readLine();
            if (line == null) {
                return null; // Fim do input
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    // 2. STRING: Lê uma única palavra (sem espaços)
    private static String nextString() throws IOException {
        return next();
    }

    // 3. FRASES/LINHAS INTEIRAS: Lê uma linha completa (incluindo espaços)
    private static String nextLine() throws IOException {
        // Se ainda sobrarem tokens na linha atual do tokenizer, limpa-os antes de avançar
        if (tokenizer != null && tokenizer.hasMoreTokens()) {
            String resto = tokenizer.nextToken("\n\r");
            tokenizer = null;
            return resto != null ? resto.trim() : "";
        }
        String line = reader.readLine();
        return line != null ? line.trim() : "";
    }

    // 4. CHAR: Lê um único caractere isolado
    private static char nextChar() throws IOException {
        String token = next();
        return (token != null && !token.isEmpty()) ? token.charAt(0) : '\0';
    }

    // 5. INT: Lê um número inteiro
    private static int nextInt() throws IOException {
        String token = next();
        return token != null ? Integer.parseInt(token) : 0;
    }

    // 6. DOUBLE: Lê um número de ponto flutuante de dupla precisão
    private static double nextDouble() throws IOException {
        String token = next();
        return token != null ? Double.parseDouble(token) : 0.0;
    }

    // 7. FLOAT: Lê um número de ponto flutuante de precisão simples
    private static float nextFloat() throws IOException {
        String token = next();
        return token != null ? Float.parseFloat(token) : 0.0f;
    }

    // 8. LONG: Útil se o problema exigir números gigantescos (ex: fatoriais, id de 64 bits)
    private static long nextLong() throws IOException {
        String token = next();
        return token != null ? Long.parseLong(token) : 0L;
    }

    public static void main(String[] args) {
        long startTime = System.nanoTime();

        try {
            // Tenta ler do arquivo local se ele existir (Seu Ambiente de Testes)
            File myFile = new File("input.txt");
            if (myFile.exists()) {
                reader = new BufferedReader(new FileReader(myFile));
            } else {
                // Caso contrário, lê da entrada padrão do sistema (Juiz Online da Maratona)
                reader = new BufferedReader(new InputStreamReader(System.in));
            }

            // =================================================================
            // REGRAS DO EXERCÍCIO / A SUA LÓGICA VAI AQUI
            // =================================================================

            /* Exemplos de uso:
               int n = nextInt();
               double preco = nextDouble();
               char opcao = nextChar();
               String nomeUnico = nextString();
               String fraseCompleta = nextLine();
            */

            // =================================================================

        } catch (IOException | NumberFormatException ignored) {
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