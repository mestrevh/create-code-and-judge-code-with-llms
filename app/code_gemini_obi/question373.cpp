/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool possible(int a, int b, int c, int d) {
    int areas[4] = {a, b, c, d};
    sort(areas, areas + 4);
    do {
        int A1 = areas[0], A2 = areas[1], A3 = areas[2], A4 = areas[3];
        // retângulo dividido por duas avenidas: {A1, A2, A3, A4} = {x*y, x*(h-y), (w-x)*y, (w-x)*(h-y)}
        // Tem que existir inteiros positivos x, y, w, h para isso.
        int sum1 = A1 + A2;
        int sum2 = A3 + A4;
        if (sum1 != sum2) continue;
        int prod1 = A1 * A4;
        int prod2 = A2 * A3;
        if (prod1 != prod2) continue;
        // Testa se existe raiz quadrada inteira positiva para prod1
        for(int x = 1; x * x <= A1; ++x){
            if(A1 % x == 0){
                int y = x;
                int h = A1 / x + A2 / x;
                int w = A1 / y + A3 / y;
                if (A2 % x == 0 && A3 % y == 0 && h > 0 && w > 0) {
                    return true;
                }
            }
        }
    } while(next_permutation(areas, areas + 4));
    return false;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (possible(a, b, c, d))
        cout << "S" << endl;
    else
        cout << "N" << endl;
}
