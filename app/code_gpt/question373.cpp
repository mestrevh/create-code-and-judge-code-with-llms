/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool possible(int a1, int a2, int a3, int a4) {
    // Tentaremos todas as permutações para ver se existe uma solução
    int v[4] = {a1, a2, a3, a4};
    sort(v, v+4);
    do {
        // v[0] v[1]
        // v[2] v[3]
        // Seja retângulo de tamanho W x H
        // Seja divisão nas posições x e y (retas perpendiculares paralelas aos lados)
        // (x)(y)              (W-x)(y)
        //   v[0]                v[1]
        // (x)(H-y)            (W-x)(H-y)
        //   v[2]                v[3]
        // Equações:
        // v[0] = x*y
        // v[1] = (W-x)*y
        // v[2] = x*(H-y)
        // v[3] = (W-x)*(H-y)
        // Total: S = v[0]+v[1]+v[2]+v[3] = W*H
        // Vamos tentar encontrar inteiros positivos x, y, W, H

        // O que pode ser deduzido:
        // x = v[0]/y, x = v[2]/(H-y)
        // W-x = v[1]/y, W-x = v[3]/(H-y)
        // Então W = x + (W-x)
        // H = y + (H-y)

        // Também: v[0]*v[3] == v[1]*v[2]
        if (v[0]*v[3] != v[1]*v[2]) continue;

        // Testa todos divisores possíveis de v[0]
        for (int y = 1; y*y <= v[0]; ++y) {
            if (v[0]%y != 0) continue;
            int x = v[0]/y;
            // Com x e y, tenta calcular W, H
            // W = x + (W-x) = x + v[1]/y, mas v[1]%y==0
            if (v[1]%y != 0) continue;
            int wx = v[1]/y;
            int W = x + wx;
            // H = y + (H-y) = y + v[2]/x, mas v[2]%x==0
            if (v[2]%x != 0) continue;
            int hy = v[2]/x;
            int H = y + hy;
            // Somatório para checagem final
            if (W <= 0 || H <= 0) continue;
            if ((W-x) <= 0 || (H-y) <= 0) continue;
            if ((W-x)*(H-y) != v[3]) continue;
            cout << "S" << endl;
            return true;
        }
    } while (next_permutation(v, v+4));
    cout << "N" << endl;
    return false;
}

int main() {
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    possible(a1, a2, a3, a4);
    return 0;
}
