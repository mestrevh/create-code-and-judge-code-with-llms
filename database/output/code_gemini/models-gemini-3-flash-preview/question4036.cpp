/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <stdio.h>
#include <math.h>

int main() {
    int x, n;
    
    if (scanf("%d %d", &x, &n) != 2) {
        return 0;
    }

    double approximation = 0.0;
    double current_term = 1.0;

    for (int i = 0; i < n; i++) {
        approximation += current_term;
        current_term = current_term * (double)x / (i + 1);
    }

    double e_val = 2.71828182845904523536;
    double exact_value = pow(e_val, (double)x);
    
    double diff = exact_value - approximation;
    if (diff < 0) {
        diff = -diff;
    }

    printf("%.3f\n", approximation);

    double ten_percent = 0.1 * exact_value;
    double one_percent = 0.01 * exact_value;

    if (diff > ten_percent) {
        printf("A aproximacao foi pouco precisa\n");
    } else if (diff > one_percent) {
        printf("A aproximacao foi muito precisa\n");
    } else {
        printf("Os valores sao praticamente iguais\n");
    }

    return 0;
}