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
                g_x = -6 / (x - 7);
                f_x = (x * x) - 7 * x + 6;
                printf("| %-5d | %10.6f | %10.6f | %10.6f | %-8s |\n",
                       iterasi, x, g_x, f_x, (fabs(f_x) < error) ? "Berhenti" : "Lanjut");
                x = g_x;
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
                g_x = ((x * x) - 6) / 7;
                f_x = (x * x) - 7 * x + 6;
                printf("| %-5d | %10.6f | %10.6f | %10.6f | %-8s |\n",
                       iterasi, x, g_x, f_x, (fabs(f_x) < error) ? "Berhenti" : "Lanjut");
                x = g_x;
                iterasi++;
            }
        }
        break;
        case 3:
        {
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
                g_x = sqrt(7 * x - 6);
                f_x = (x * x) - 7 * x + 6;
                printf("| %-5d | %10.6f | %10.6f | %10.6f | %-8s |\n",
                       iterasi, x, g_x, f_x, (fabs(f_x) < error) ? "Berhenti" : "Lanjut");
                x = g_x;
                iterasi++;
            }
        }
        }
        break;
    case 2:
        printf("Anda memilih Metode Newton Raphson.\n");
        // Tambahkan kode untuk metode Newton Raphson di sini
        {
        printf("Anda memilih Metode Newton Raphson.\n");
        double x, x_old, f_x, f_x_aksen, x_new;
        int iterasi = 1;
        const double error = 0.01;
        x = 0;
        printf("+-------+------------+-------------+------------+------------+------------+------------+\n");
        printf("| %-5s | %-10s | %-10s | %-10s | %-10s | %-10s | %-12s |\n",
               "iter", "x_old", "fx", "fx_aksen", "x_new", "galat", "keterangan");
        printf("+-------+------------+-------------+------------+------------+------------+------------+\n");

        for (int i = 0; i < 10; i++)
        {
            x_old = x;
            f_x = (x_old * x_old) - 7 * x_old + 6; // f(x) = x^2 - 7x + 6
            f_x_aksen = 2 * x_old - 7;             // f'(x) = 2x - 7
            x_new = x_old - (f_x / f_x_aksen);
            printf("| %-5d | %-10.6f | %-10.6f | %-10.6f | %-10.6f | %-10.6f | %-12s |\n",
                   iterasi, x_old, f_x, f_x_aksen, x_new, fabs(f_x), (fabs(f_x) < error) ? "Berhenti" : "Lanjut");
            x = x_new;
            iterasi++;
        }
    }
        break;
    case 3:
    {
        printf("Anda memilih Metode Secant.\n");
        // Tambahkan kode untuk metode Secant di sini
        int iterasi = 1;
        double x0, x1, f_x1, f_xi, x_new;
        double const error = 0.001;
        x0 = 0;
        x1 = 0.5;
        printf("+-------+------------+------------+------------+------------+------------+------------+------------+\n");
        printf("| %-5s | %-10s | %-10s | %-10s | %-10s | %-10s | %-12s | %-9s |\n",
               "Iter", "x0", "x1", "f_x1", "f_xi", "x_new", "|x_new-x1|", "Status");
        printf("+-------+------------+------------+------------+------------+------------+------------+------------+\n");
        
        for (int i = 0; i < 15; i++)
        {
            f_x1 = (x0 * x0) - 7 * x0 + 6; 
            f_xi = (x1 * x1) - 7 * x1 + 6; 
            x_new = x1 - ((f_xi * (x1 - x0)) / (f_xi - f_x1)); 
            printf("| %-5d | %10.6f | %10.6f | %10.6f | %10.6f | %10.6f | %12.6f | %-9s |\n",
            iterasi, x0, x1, f_x1, f_xi, x_new, fabs(x_new - x1), (fabs(f_x1) < error) ? "Berhenti" : "Lanjut");
            x0 = x1;
            x1 = x_new;
            iterasi++;
        }

        break;
    }
    default:
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
    }
}