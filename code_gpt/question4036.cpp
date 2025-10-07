/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <stdio.h>
#include <math.h>

int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    
    double aproximacao = 1.0, termo = 1.0;
    
    for (int i = 1; i < n; i++) {
        termo *= (double)x / i;
        aproximacao += termo;
    }
    
    double valor_exato = exp(x);
    double diferenca = fabs(valor_exato - aproximacao);
    
    printf("%.3f\n", aproximacao);
    
    if (diferenca > 0.1 * valor_exato)
        printf("A aproximacao foi pouco precisa\n");
    else if (diferenca > 0.01 * valor_exato)
        printf("A aproximacao foi muito precisa\n");
    else
        printf("Os valores sao praticamente iguais\n");
    
    return 0;
}
