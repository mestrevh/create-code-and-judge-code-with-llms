/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isInfected(int n) {
    for (int a = 0; a <= n; ++a) {
        for (int b = 0; b <= n; ++b) {
            for (int c = 0; c <= n; ++c) {
                if (a * b * c == n && a + b + c == 19) return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;
        cout << (isInfected(n) ? "INFECTADO" : "SAFE") << endl;
    }
    return 0;
}
