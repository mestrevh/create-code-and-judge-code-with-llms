/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < 0 || b < 0 || c < 0 || d < 0) {
        cout << "lurn maf :(" << endl;
        return 0;
    }

    int w = (a == 0) ? (b * b) : a;
    int x = (a > 0) ? 2 : 0;
    int y = (b + x > c) ? w - c : 0;
    int z = (c == 0) ? 500 : (2 - (d / 1000.0) >= 0 ? (1000 - d) : 0);

    cout << w << " laranjas" << endl;
    cout << b + x << " bananas" << endl;
    cout << c + y << " ovos" << endl;
    cout << d + z << " mL de leite" << endl;

    return 0;
}
