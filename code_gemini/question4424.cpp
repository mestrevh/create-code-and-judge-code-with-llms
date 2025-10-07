/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    int r1, div1, r2, div2, r3, div3;
    cin >> r1 >> div1 >> r2 >> div2 >> r3 >> div3;

    for (int x = 0; x <= div1 * div2 * div3; ++x) {
        if (x % div1 == r1 && x % div2 == r2 && x % div3 == r3) {
            cout << x << endl;
            return 0;
        }
    }

    return 0;
}
