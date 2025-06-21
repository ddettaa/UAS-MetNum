#include <stdio.h>

int main (){
    int pilihan;
    printf("\t \t \t Ulangan Akhir Semester Metode Numerik\n");
    printf("1. Metode Iterasi Sederhana\n");
    printf("2. Metode Newton Raphson\n");
    printf("3. Metode Secant\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
        int rumus;
        printf("Pilih Rumus yang akan dipakai\n");
        printf("1. Rumus 1 (g(x)=-6/x-7)\n");
        printf("2. Rumus 2 (g(x)=x^2-6/7) \n");
        printf("3. Rumus 3 (g(x)=SQRT(7x-6))\n");
        printf("Pilihan: ");
        scanf("%d", &rumus);
        switch(rumus){
            case 1:
                printf("Anda memilih Rumus 1.\n");
                break;
        }
            break;
        case 2:
            printf("Anda memilih Metode Newton Raphson.\n");
            // Tambahkan kode untuk metode Newton Raphson di sini
            break;
        case 3:
            printf("Anda memilih Metode Secant.\n");
            // Tambahkan kode untuk metode Secant di sini
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
    }
}
