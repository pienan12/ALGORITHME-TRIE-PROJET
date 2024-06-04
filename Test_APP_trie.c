
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genererTableauAleatoire(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 1000;
    }
}

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
    srand(time(0));
    int tailles[] = {100, 200, 400, 600, 800, 1000};
    int num_tailles = sizeof(tailles) / sizeof(tailles[0]);

    for (int i = 0; i < num_tailles; i++) {
        int n = tailles[i];
        int array[n];

        genererTableauAleatoire(array, n);

        clock_t debut, fin;
        double temps_cpu_utilise;

        // Tester le tri par sélection amélioré
        int array_copy[n];
        for (int j = 0; j < n; j++) {
            array_copy[j] = array[j];
        }

        debut = clock();
        triSelectionAmeliore(array_copy, n);
        fin = clock();
        temps_cpu_utilise = ((double) (fin - debut)) / CLOCKS_PER_SEC;
        printf("Tri par sélection amélioré sur un tableau de taille %d a pris %f secondes\n", n, temps_cpu_utilise);

        // Tester le tri par sélection classique
        for (int j = 0; j < n; j++) {
            array_copy[j] = array[j];
        }

        debut = clock();
        triSelectionClassique(array_copy, n);
        fin = clock();
        temps_cpu_utilise = ((double) (fin - debut)) / CLOCKS_PER_SEC;
        printf("Tri par sélection classique sur un tableau de taille %d a pris %f secondes\n", n, temps_cpu_utilise);
    }

    return 0;
}
