#include <stdio.h>
#include <math.h>

int main()
{
    int pilihan;
    printf("\t \t \t Ulangan Akhir Semester Metode Numerik\n");
    printf("1. Metode Iterasi Sederhana\n");
    printf("2. Metode Newton Raphson\n");
    printf("3. Metode Secant\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        int rumus;
        printf("Pilih Rumus yang akan dipakai\n");
        printf("1. Rumus 1 (g(x)=-6/x-7)\n");
        printf("2. Rumus 2 (g(x)=x^2-6/7) \n");
        printf("3. Rumus 3 (g(x)=SQRT(7x-6))\n");
        printf("Pilihan: ");
        scanf("%d", &rumus);
        switch (rumus)
        {
        case 1:
        {
            printf("Anda memilih Rumus 1.\n");
            double i, x, g_x, f_x;
            int iterasi = 1;
            const double error = 0.001;
            x = 2;

            printf("+-------+------------+------------+------------+------------+\n");
            printf("| %-5s | %-10s | %-10s | %-10s | %-8s |\n",
                   "Iter", "x", "g(x)", "f(x)", "Status");
            printf("+-------+------------+------------+------------+------------+\n");

            for (i = 0; i < 15; i++)
            {
                double x_old = x;
                g_x = -6 / (x_old - 7);
                x = g_x;
                f_x = (x * x) - 7 * x + 6;
                printf("| %-5d | %10.6f | %10.6f | %10.6f | %-8s |\n",
                       iterasi, x_old, g_x, f_x, (fabs(f_x) < error) ? "Berhenti" : "Lanjut");
                iterasi++;
            }
        }
        break;
        case 2:
        {
            printf("Anda memilih Rumus 2.\n");
            int iterasi = 1;
            double i, x, g_x, f_x;
            const double error = 0.001;
            x = 2;
            printf("+-------+------------+------------+------------+------------+\n");
            printf("| %-5s | %-10s | %-10s | %-10s | %-8s |\n",
                   "Iter", "x", "g(x)", "f(x)", "Status");
            printf("+-------+------------+------------+------------+------------+\n");

            for (i = 0; i < 15; i++)
            {
                double x_old = x;
                g_x = ((x_old * x_old) - 6) / 7;
                x = g_x;
                f_x = (x * x) - 7 * x + 6;
                printf("| %-5d | %10.6f | %10.6f | %10.6f | %-8s |\n",
                       iterasi, x_old, g_x, f_x, (fabs(f_x) < error) ? "Berhenti" : "Lanjut");
                iterasi++;
            }
        }
        break;
        case 3:{
             printf("Anda memilih Rumus 3.\n");
            int iterasi = 1;
            double i, x, g_x, f_x;
            const double error = 0.001;
            x = 3;
            printf("+-------+------------+------------+------------+------------+\n");
            printf("| %-5s | %-10s | %-10s | %-10s | %-8s |\n",
                   "Iter", "x", "g(x)", "f(x)", "Status");
            printf("+-------+------------+------------+------------+------------+\n");

            for (i = 0; i < 25; i++)
            {
                double x_old = x;
                g_x = sqrt(7 * x_old - 6);
                x = g_x;
                f_x = (x * x) - 7 * x + 6;
                printf("| %-5d | %10.6f | %10.6f | %10.6f | %-8s |\n",
                       iterasi, x_old, g_x, f_x, (fabs(f_x) < error) ? "Berhenti" : "Lanjut");
                iterasi++;
            }
        }
        }
        break;
    case 2:
        printf("Anda memilih Metode Newton Raphson.\n");
        {
            int iterasi = 1;
            double i, x, g_x, f_x, f_prime;
            const double error = 0.001;
            x = 0;

            printf("+-------+------------+------------+------------+------------+\n");
            printf("| %-5s | %-10s | %-10s | %-10s | %-8s |\n",
                   "Iter", "x", "g(x)", "f(x)", "Status");
            printf("+-------+------------+------------+------------+------------+\n");

            for (i = 0; i < 15; i++)
            {
                double x_old = x;
                f_x = (x_old * x_old) - 7 * x_old + 6;
                f_prime = 2 * x_old - 7;
                g_x = x_old - f_x / f_prime;
                x = g_x;
                f_x = (x * x) - 7 * x + 6;
                printf("| %-5d | %10.6f | %10.6f | %10.6f | %-8s |\n",
                       iterasi, x_old, g_x, f_x,
                       (fabs(f_x) < error) ? "Berhenti" : "Lanjut");
                iterasi++;
            }
        }
        break;
    case 3:
        printf("Anda memilih Metode Secant.\n");
        {
            int iterasi = 1;
            double i, x0, x1, g_x, f_x;
            const double error = 0.001;
            x0 = 0;
            x1 = 0.5;

            printf("+-------+------------+------------+------------+------------+\n");
            printf("| %-5s | %-10s | %-10s | %-10s | %-8s |\n",
                   "Iter", "x", "g(x)", "f(x)", "Status");
            printf("+-------+------------+------------+------------+------------+\n");

            for (i = 0; i < 15; i++)
            {
                double f_x0 = (x0 * x0) - 7 * x0 + 6;
                double f_x1 = (x1 * x1) - 7 * x1 + 6;
                if (fabs(f_x1 - f_x0) < 1e-12)
                    break;
                double x_old = x1;
                g_x = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);
                x0 = x1;
                x1 = g_x;
                f_x = (x1 * x1) - 7 * x1 + 6;
                printf("| %-5d | %10.6f | %10.6f | %10.6f | %-8s |\n",
                       iterasi, x_old, g_x, f_x,
                       (fabs(f_x) < error) ? "Berhenti" : "Lanjut");
                iterasi++;
                if (fabs(f_x) < error)
                    break;
            }
        }
        break;
    default:
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
    }
}
