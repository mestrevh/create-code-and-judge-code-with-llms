/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool check(int a1, int a2, int a3, int a4) {
    int total = a1 + a2 + a3 + a4;
    for (int i = 1; i * i <= total; ++i) {
        if (total % i != 0) continue;
        int h = i, w = total / i;
        // h = altura (dividida em 2 partes a e h-a), w = largura (dividida em b e w-b)
        // Áreas:
        // A1 = a * b
        // A2 = (h - a) * b
        // A3 = a * (w - b)
        // A4 = (h - a) * (w - b)
        int area[4] = {a1, a2, a3, a4};
        sort(area, area + 4);
        do {
            int A1 = area[0], A2 = area[1], A3 = area[2], A4 = area[3];
            // calculando b das 2 primeiras equações
            // A1 = a*b => b = A1/a, a divide A1
            // depois, A2 = (h-a)*b => (h-a) = A2/b, b divide A2
            for (int a = 1; a < h; ++a) {
                if (A1 % a != 0) continue;
                int b = A1 / a;
                if (b <= 0 || b >= w) continue;
                if (A2 % b != 0) continue;
                if (A3 % a != 0) continue;
                if (A4 % (h - a) != 0) continue;
                if ((h - a) <= 0 || (w - b) <= 0) continue;
                if (A2 / b != (h - a)) continue;
                if (A3 / a != (w - b)) continue;
                if (A4 / (h - a) != (w - b)) continue;
                return true;
            }
        } while (next_permutation(area, area+4));
    }
    return false;
}

int main() {
    int A1, A2, A3, A4;
    cin >> A1 >> A2 >> A3 >> A4;
    if (check(A1, A2, A3, A4))
        cout << "S" << endl;
    else
        cout << "N" << endl;
    return 0;
}
