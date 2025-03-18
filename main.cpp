#include <stdio.h>
#include <stdbool.h>


bool isPalindrome(int x) {
    // Si x es negativo o termina en 0 pero no es 0, no puede ser palíndromo
    if (x < 0 || (x % 10 == 0 && x != 0)) return false; // 2 operaciones


    int revertedHalf = 0; // 1 operación
    int numOps = 3; // Contador de operaciones básicas (las previas)


    while (x > revertedHalf) { // 1 comparación por iteración
        revertedHalf = revertedHalf * 10 + x % 10; // 2 operaciones por iteración
        x /= 10; // 1 operación por iteración
        numOps += 4;
    }


    // Comparamos la mitad revertida con la original
    bool result = (x == revertedHalf || x == revertedHalf / 10); // 2 operaciones
    numOps += 2;


    printf("Número total de operaciones: %d\n", numOps);
    return result;
}


int main() {
    int x;
    printf("Ingrese un número: ");
    scanf("%d",&x);


    if (isPalindrome(x)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
 
