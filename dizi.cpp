#include <stdio.h>

int main() {
    int n, i, search;
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d", &n); // eleman istiyoruz
    int array[n];
    printf("Dizinin elemanlarini giriniz: ");
    for (i = 0; i < n; i++) // istenen koşulları kontrol etmek için for döngüsüne alıyoruz istenen elemanları
        scanf("%d", &array[i]);
    printf("Aranacak elemani giriniz: ");
    scanf("%d", &search); // dizide bulunacak elemanı istiyoruz
    for (i = 0; i < n; i++) { // aranan elemanın dizinin içinde olup olmadığını kontrol ediyoruz
        if (array[i] == search) { // eleman varsa bu if kodu çalışır ve yazdırılır
            printf("%d elemani dizide bulundu.\n", search);
            break;
        }
    }
    if (i == n) // eleman yoksa bu if koşulu kullanılır ve kullanıcıya bildirilir
        printf("%d elemani dizide bulunamadi.\n", search);
    return 0;
}
