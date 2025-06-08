#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fungsi Lotka-Volterra
double dx_dt(double x, double y, double alpha, double beta) {
    return alpha * x - beta * x * y;
}

double dy_dt(double x, double y, double delta, double gamma) {
    return delta * x * y - gamma * y;
}

// Metode Runge-Kutta untuk simulasi sistem dinamis
void runge_kutta(double x0, double y0, double alpha, double beta, double delta, double gamma, double h, int steps) {
    double x = x0, y = y0;

    printf("Iterasi\tPopulasi Predator\tPopulasi Prey\n");
    for (int i = 0; i < steps; ++i) {
        double k1x = h * dx_dt(x, y, alpha, beta);
        double k1y = h * dy_dt(x, y, delta, gamma);

        double k2x = h * dx_dt(x + k1x / 2, y + k1y / 2, alpha, beta);
        double k2y = h * dy_dt(x + k1x / 2, y + k1y / 2, delta, gamma);

        double k3x = h * dx_dt(x + k2x / 2, y + k2y / 2, alpha, beta);
        double k3y = h * dy_dt(x + k2x / 2, y + k2y / 2, delta, gamma);

        double k4x = h * dx_dt(x + k3x, y + k3y, alpha, beta);
        double k4y = h * dy_dt(x + k3x, y + k3y, delta, gamma);

        x += (k1x + 2 * k2x + 2 * k3x + k4x) / 6;
        y += (k1y + 2 * k2y + 2 * k3y + k4y) / 6;

        printf("%d\t%.6f\t\t%.6f\n", i + 1, x, y);
    }
}

// Simpan hasil simulasi ke file dengan nama yang dimasukkan penggunaa.
void simpan_hasil(double x0, double y0, double alpha, double beta, double delta, double gamma, double h, int steps) {
    char nama_file[100];
    printf("Masukkan nama file untuk menyimpan hasil (contoh: hasil_simulasi.csv): ");
    scanf("%s", nama_file);

    FILE *file = fopen(nama_file, "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menyimpan hasil.\n");
        return;
    }

    double x = x0, y = y0;
    fprintf(file, "Iterasi,Populasi Predator,Populasi Prey\n");
    for (int i = 0; i < steps; ++i) {
        double k1x = h * dx_dt(x, y, alpha, beta);
        double k1y = h * dy_dt(x, y, delta, gamma);

        double k2x = h * dx_dt(x + k1x / 2, y + k1y / 2, alpha, beta);
        double k2y = h * dy_dt(x + k1x / 2, y + k1y / 2, delta, gamma);

        double k3x = h * dx_dt(x + k2x / 2, y + k2y / 2, alpha, beta);
        double k3y = h * dy_dt(x + k2x / 2, y + k2y / 2, delta, gamma);

        double k4x = h * dx_dt(x + k3x, y + k3y, alpha, beta);
        double k4y = h * dy_dt(x + k3x, y + k3y, delta, gamma);

        x += (k1x + 2 * k2x + 2 * k3x + k4x) / 6;
        y += (k1y + 2 * k2y + 2 * k3y + k4y) / 6;

        fprintf(file, "%d,%.6f,%.6f\n", i + 1, x, y);
    }

    fclose(file);
    printf("Hasil simulasi berhasil disimpan ke file '%s'.\n", nama_file);
}

// Hitung rata-rata populasi
void hitung_rata_rata(double x0, double y0, double alpha, double beta, double delta, double gamma, double h, int steps) {
    double x = x0, y = y0;
    double total_x = 0, total_y = 0;

    for (int i = 0; i < steps; ++i) {
        double k1x = h * dx_dt(x, y, alpha, beta);
        double k1y = h * dy_dt(x, y, delta, gamma);

        double k2x = h * dx_dt(x + k1x / 2, y + k1y / 2, alpha, beta);
        double k2y = h * dy_dt(x + k1x / 2, y + k1y / 2, delta, gamma);

        double k3x = h * dx_dt(x + k2x / 2, y + k2y / 2, alpha, beta);
        double k3y = h * dy_dt(x + k2x / 2, y + k2y / 2, delta, gamma);

        double k4x = h * dx_dt(x + k3x, y + k3y, alpha, beta);
        double k4y = h * dy_dt(x + k3x, y + k3y, delta, gamma);

        x += (k1x + 2 * k2x + 2 * k3x + k4x) / 6;
        y += (k1y + 2 * k2y + 2 * k3y + k4y) / 6;

        total_x += x;
        total_y += y;
    }

    printf("Rata-rata populasi predator: %.6f\n", total_x / steps);
    printf("Rata-rata populasi prey: %.6f\n", total_y / steps);
}

// Tambahkan fitur stiker
void tampilkan_stiker() {
    printf("\n=========================\n");
    printf("   Terima Kasih! :)      \n");
    printf(" Proyek UAS Komputasi    \n");
    printf("       Numerik           \n");
    printf("=========================\n");
}

// Menu utama
void menu() {
    printf("\n=== Menu Utama ===\n");
    printf("1. Simulasi Lotka-Volterra\n");
    printf("2. Ubah Parameter\n");
    printf("3. Simpan Hasil Simulasi ke File\n");
    printf("4. Hitung Rata-rata Populasi\n");
    printf("5. Tampilkan Stiker\n");
    printf("6. Keluar\n");
    printf("Pilih opsi: ");
}

int main() {
    double alpha = 0.1, beta = 0.02, delta = 0.01, gamma = 0.1;
    double x0 = 40, y0 = 9, h = 0.1;
    int steps = 100;
    int pilihan;

    do {
        menu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("\nSimulasi Lotka-Volterra menggunakan metode Runge-Kutta\n");
                runge_kutta(x0, y0, alpha, beta, delta, gamma, h, steps);
                break;

            case 2:
                printf("\nUbah Parameter:\n");
                printf("Masukkan alpha: ");
                scanf("%lf", &alpha);
                printf("Masukkan beta: ");
                scanf("%lf", &beta);
                printf("Masukkan delta: ");
                scanf("%lf", &delta);
                printf("Masukkan gamma: ");
                scanf("%lf", &gamma);
                printf("Masukkan populasi awal predator (x0): ");
                scanf("%lf", &x0);
                printf("Masukkan populasi awal prey (y0): ");
                scanf("%lf", &y0);
                printf("Masukkan langkah waktu (h): ");
                scanf("%lf", &h);
                printf("Masukkan jumlah iterasi (steps): ");
                scanf("%d", &steps);
                printf("Parameter berhasil diubah!\n");
                break;

            case 3:
                printf("\nMenyimpan hasil simulasi ke file...\n");
                simpan_hasil(x0, y0, alpha, beta, delta, gamma, h, steps);
                break;

            case 4:
                printf("\nMenghitung rata-rata populasi...\n");
                hitung_rata_rata(x0, y0, alpha, beta, delta, gamma, h, steps);
                break;

            case 5:
                tampilkan_stiker();
                break;

            case 6:
                printf("\nKeluar dari program. Terima kasih proyek UAS Komputasi Numerik!\n");
                break;

            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 6);

    return 0;
}