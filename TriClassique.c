#include <stdio.h>

void triSelectionClassique(int array[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

void imprimerTableau(int array[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {64, 25, 12, 22,22, 11};
    int n = sizeof(array) / sizeof(array[0]);
    triSelectionClassique(array, n);
    printf("Tableau trié par trie de selection classique: \n");
    imprimerTableau(array, n);
    return 0;
}
