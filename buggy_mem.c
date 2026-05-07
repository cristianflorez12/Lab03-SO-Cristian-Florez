#include <stdio.h>
#include <stdlib.h>

int main() {
    // Corrección 1: Asegurar tamaño suficiente para el índice usado
    int *p = malloc(5 * sizeof(int)); 
    if (p == NULL) return 1;

    for (int i = 0; i < 5; i++) {
        p[i] = i; // Acceso seguro dentro de los límites
    }

    // Corrección 2: Liberar la segunda asignación para evitar fuga
    int *q = malloc(100);
    if (q != NULL) {
        free(q); 
    }

    // Corrección 3: No usar el puntero p después de esta línea
    free(p); 

    printf("Programa finalizado sin errores de memoria.\n");
    return 0;
}