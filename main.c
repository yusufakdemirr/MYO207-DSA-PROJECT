#include <stdio.h>

// Yusuf Akdemir
// 2420171019
// BTK Akademi Sertifika Bağlantım: https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=vpWcnPAMo8

void dizi_yazdir(int dizi[], int BOYUT) {
    int i;
    for (i = 0; i < BOYUT; i++) {
        printf("%3d", dizi[i]);
    }
    printf("\n");
}

void takas(int *ap, int *bp) {
    int gecici;
    gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}

void baloncuk_sirala(int dizi[], int BOYUT) {
    int i, j;
    int takas_oldu; 
    for (i = 1; i < BOYUT; i++) { 
        takas_oldu = 0; 
        for (j = 0; j < BOYUT - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                takas(dizi + j, dizi + j + 1);
                takas_oldu = 1; 
            }
        }
        if (takas_oldu == 0) {
            break;
        }
    }
}

int ikili_arama(int dizi[], int BOYUT, int aranan) {
    int ilk = 0;
    int son = BOYUT - 1;
    int orta;

    while (ilk <= son) {
        orta = (ilk + son) / 2; // orta eleman konumu

        if (dizi[orta] == aranan) {
            return orta;
        }
        else if (aranan < dizi[orta]) {
            son = orta - 1;
        }
        else {
            ilk = orta + 1;
        }
    }
    return -1; 
}

int main() {
    int A[] = {25, 14, 3, 99, 56, 11, 40, 7, 22, 60}; 
    int N = sizeof(A) / sizeof(A[0]);
    int sayi, sonuc;

    printf("Dizi: ");
    dizi_yazdir(A, N);

    baloncuk_sirala(A, N);

    printf("Sirali Dizi: ");
    dizi_yazdir(A, N);

    printf("Aranacak sayi: ");
    scanf("%d", &sayi);

    sonuc = ikili_arama(A, N, sayi);

    if (sonuc != -1) {
        printf("Sonuc: %d degeri %d. konumda bulundu.\n", sayi, sonuc);
    } else {
        printf("Sonuc: Eleman bulunamadi.\n");
    }

    return 0;
}