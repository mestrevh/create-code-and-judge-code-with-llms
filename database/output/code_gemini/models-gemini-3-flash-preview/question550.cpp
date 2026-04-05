/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Função que calcula os elementos de três vetores pseudo-aleatórios e 
 * retorna o maior elemento de cada um.
 * 
 * Regras:
 * Y[0] = seedY, Y[i] = (Y[i - 1] * A + B) % C
 * X[0] = seedX, X[i] = (X[i - 1] * B + C) % A
 * Z[0] = seedZ, Z[i] = (Z[i - 1] * C + A) % B
 */
void calcularMaximos(int A, int B, int C, int seedX, int seedY, int seedZ, long long &maxX, long long &maxY, long long &maxZ) {
    long long X[10], Y[10], Z[10];
    
    X[0] = seedX;
    Y[0] = seedY;
    Z[0] = seedZ;
    
    maxX = X[0];
    maxY = Y[0];
    maxZ = Z[0];
    
    for (int i = 1; i < 10; ++i) {
        X[i] = (X[i - 1] * (long long)B + C) % A;
        if (X[i] > maxX) maxX = X[i];
        
        Y[i] = (Y[i - 1] * (long long)A + B) % C;
        if (Y[i] > maxY) maxY = Y[i];
        
        Z[i] = (Z[i - 1] * (long long)C + A) % B;
        if (Z[i] > maxZ) maxZ = Z[i];
    }
}

/**
 * Função Modulo que aplica a operação soma mod((A/B)+C)
 */
long long Modulo(long long soma, int A, int B, int C) {
    long long divisor = (long long)(A / B) + C;
    if (divisor == 0) return 0;
    return soma % divisor;
}

int main() {
    // Otimização de I/O padrão em C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, seedX, seedY, seedZ;
    
    // Leitura contínua até o fim do arquivo (EOF) conforme casos de teste
    while (cin >> A >> B >> C >> seedX >> seedY >> seedZ) {
        long long maxX, maxY, maxZ;
        
        // 1) Calcula elementos e obtém os maiores
        calcularMaximos(A, B, C, seedX, seedY, seedZ, maxX, maxY, maxZ);
        
        // 2) Soma todos os elementos máximos
        long long soma = maxX + maxY + maxZ;
        
        // 3) Faz o valor da soma se tornar soma mod((A/B)+C)
        soma = Modulo(soma, A, B, C);
        
        // 4) Imprime soma seguido de quebra de linha
        cout << soma << "\n";
    }

    return 0;
}