/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cstdio>

int main() {
    int A, B, C, D, E, F;
    
    // Using scanf to handle the specific format "Ax + By = C"
    // The spaces in the format string handle optional whitespace.
    if (scanf("%dx + %dy = %d", &A, &B, &C) != 3) return 0;
    if (scanf("%dx + %dy = %d", &D, &E, &F) != 3) return 0;

    // Applying Cramer's Rule for a 2x2 system:
    // Ax + By = C
    // Dx + Ey = F
    // det = A*E - B*D
    // detX = C*E - B*F
    // detY = A*F - C*D
    
    double det = (double)A * E - (double)B * D;
    double detX = (double)C * E - (double)B * F;
    double detY = (double)A * F - (double)C * D;

    double x = detX / det;
    double y = detY / det;

    // Output with 2 decimal places
    printf("%.2f\n%.2f\n", x, y);

    return 0;
}