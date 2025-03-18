#include <iostream>
#include <algorithm>
using namespace std;
int teamChemistry(int skill[], int n) {
    sort(skill, skill + n);
    int targetSum = skill[0] + skill[n - 1];
    int totalChemistry = 0;
    for (int i = 0; i < n / 2; ++i) {
        int left = skill[i];
        int right = skill[n - 1 - i];
        if (left + right != targetSum) {
            return -1;  
        }
        totalChemistry += left * right;
    }
    return totalChemistry;
}
int main() {
    int n;
    printf("Ingresa el número de jugadores (debe ser par): ");
    scanf("%d", &n);
    if (n % 2 != 0) {
        printf("-1\n"); 
        return 0;
    }
    int skill[n];
    printf("Ingresa las habilidades de los jugadores:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &skill[i]);
    }
    int result = teamChemistry(skill, n);
    if (result == -1) {
        printf("-1\n"); 
    } else {
        printf("La suma de la química es: %d\n", result);
    }
    return 0;
}
