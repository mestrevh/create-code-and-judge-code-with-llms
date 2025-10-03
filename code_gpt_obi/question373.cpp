/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool possible(int a1, int a2, int a3, int a4) {
    int v[4] = {a1, a2, a3, a4};
    sort(v, v + 4);
    do {
        int b = v[0] + v[1];
        int d = v[2] + v[3];
        // as quatro áreas seriam (x * y), ((B-x) * y), (x * (D-y)), ((B-x)*(D-y)), em algum arranjo
        // Devemos ter: (v[0]+v[1])*(v[2]+v[0]) == v[0]+v[1]+v[2]+v[3] em duas partições
        // Tentar calcular x e y:
        // v[0]=x*y
        // v[1]=(B-x)*y
        // v[2]=x*(D-y)
        // v[3]=(B-x)*(D-y)
        // Vamos tentar para cada "decomposição" de v[0]+v[1] (B), e v[0]+v[2] (D)
        int B = v[0] + v[1];
        int D = v[0] + v[2];
        // x*y = v[0]
        // (B-x)*y = v[1] -> B*y - x*y = v[1] => B*y - v[0] = v[1] => B*y = v[1] + v[0] => y = (v[1]+v[0])/B
        if ((v[1]+v[0]) % B != 0) continue;
        int y = (v[1]+v[0]) / B;
        if (y <= 0) continue;
        if (v[0] % y != 0) continue;
        int x = v[0] / y;
        if (x <= 0) continue;
        if (D < y) continue;
        int Dy = D - y;
        if (v[2] % Dy != 0) continue;
        int x2 = v[2] / Dy;
        if (x2 != x) continue;
        int Bx = B - x;
        if (v[3] % Dy != 0) continue;
        int bx2 = v[3] / Dy;
        if (bx2 != Bx) continue;
        return true;
    } while (next_permutation(v, v + 4));
    return false;
}

int main() {
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    cout << (possible(a1, a2, a3, a4) ? 'S' : 'N') << endl;
}
