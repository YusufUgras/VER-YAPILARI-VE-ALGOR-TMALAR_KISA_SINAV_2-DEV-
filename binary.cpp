#include <stdio.h>
#include <stdlib.h>

// qsort fonksiyonu için karşılaştırma fonksiyonu
int compare(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

// Binary Search fonksiyonu
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        // Eğer aranan eleman ortadaki elemana eşitse
        if (arr[mid] == x)
            return mid;
        // Eğer aranan eleman ortadaki elemandan küçükse
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        // Eğer aranan eleman ortadaki elemandan büyükse
        return binarySearch(arr, mid + 1, r, x);
    }
    // Eğer eleman bulunamazsa
    return -1;
}

int main(void) {
    int dizi[] = {4,8,3,84,47,76,9,24,68};
    int n = sizeof(dizi)/sizeof(dizi[0]);
    int x = 47;
    // Diziyi sıralama
    qsort(dizi, n, sizeof(int), compare);
    // Binary Search ile arama yapma
    int result = binarySearch(dizi, 0, n-1, x);
    // Sonucu yazdırma
    (result == -1) ? printf("eleman dizide yok")
                   : printf("eleman dizide var: %d", result);
    return 0;
}
