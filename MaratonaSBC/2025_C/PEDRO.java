package maratona_2025.prova;
import java.util.Scanner;

public class C_Collatz_polinomial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();

        long p = 0;
        for (int i = n; i >= 0; i--) {
            int coeficient = sc.nextInt();
            if (coeficient == 1) {
                p |= (1L << i);
            }
        }

        int steps = 0;

        while (p != 1) {
            if ((p % 2) != 0) {
                p = (p << 1) ^ p ^ 1;
            } else {
                p = p >> 1;
            }
            steps++;
        }

        System.out.println(steps);
        sc.close();
    }
}
