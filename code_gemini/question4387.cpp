/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long insensibility = 0;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        insensibility += pow(x1 - x2, 2) + pow(y1 - y2, 2);
    }

    cout << insensibility << endl;

    return 0;
}
