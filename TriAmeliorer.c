#include <stdio.h>

void triSelectionAmeliore(int array[], int n) {
    int i = 0;
    while (i < n - 1) {
        int Max = array[i];
        int file[n];
        int tailleFile = 0;

        for (int j = i; j < n; j++) {
            if (array[j] > Max) {
                Max = array[j];
                tailleFile = 0;
                file[tailleFile++] = j;
            } else if (array[j] == Max) {
                file[tailleFile++] = j;
            }
        }

        while (tailleFile > 0) {
            int index = file[--tailleFile];
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
            i++;
        }
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
    triSelectionAmeliore(array, n);
    printf("Tableau trié par tri de selection Ameliorer: \n");
    imprimerTableau(array, n);
    return 0;
}